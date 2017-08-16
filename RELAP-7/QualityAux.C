#include "QualityAux.h"

template <>
InputParameters
validParams<QualityAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("A", "Cross-sectional area");
  params.addRequiredCoupledVar("arhoA_liquid", "Liquid mass equation variable: alpha*rho*A");
  params.addRequiredCoupledVar("arhoA_vapor", "Vapor mass equation variable: alpha*rho*A");
  params.addRequiredCoupledVar("H_liquid", "Specific total enthalpy of liquid");
  params.addRequiredCoupledVar("H_vapor", "Specific total enthalpy of vapor");
  params.addRequiredCoupledVar("p_liquid", "Pressure of the liquid phase");
  params.addRequiredCoupledVar("vel_liquid", "Velocity of the liquid");
  params.addRequiredCoupledVar("vel_vapor", "Velocity of the vapor");
  params.addRequiredParam<UserObjectName>("fp",
                                          "The name of the 2-phase fluid properties user object");
  return params;
}

QualityAux::QualityAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _area(coupledValue("A")),
    _arhoA_liquid(coupledValue("arhoA_liquid")),
    _arhoA_vapor(coupledValue("arhoA_vapor")),
    _h_liquid(coupledValue("H_liquid")),
    _h_vapor(coupledValue("H_vapor")),
    _velocity_liquid(coupledValue("vel_liquid")),
    _velocity_vapor(coupledValue("vel_vapor")),
    _p_liquid(coupledValue("p_liquid")),
    _fp(getUserObject<TwoPhaseFluidProperties>("fp")),
    _fp_liquid(getUserObjectByName<SinglePhaseFluidProperties>(_fp.getLiquidName()))
{
}

Real
QualityAux::computeValue()
{
  Real p_liquid = _p_liquid[_qp];
  // ensure pressure is positive
  if (p_liquid < 1.0e-5)
    p_liquid = 1.0e-5;
  Real T_sat = _fp.T_sat(p_liquid);
  Real h_sat_liquid = _fp_liquid.h(p_liquid, T_sat);
  Real quality = 0;

  if (_velocity_liquid[_qp] * _velocity_vapor[_qp] > 0.0)
  {
    Real g_liquid = _arhoA_liquid[_qp] * _velocity_liquid[_qp] / _area[_qp];
    Real g_vapor = _arhoA_vapor[_qp] * _velocity_vapor[_qp] / _area[_qp];
    Real g = g_liquid + g_vapor;
    quality = (((g_liquid * _h_liquid[_qp] + g_vapor * _h_vapor[_qp]) / g) - h_sat_liquid) /
              (_h_vapor[_qp] - h_sat_liquid);
  }
  else
  {
    quality = FlowRegimeDependentParameters::getStaticFlowQuality(_arhoA_liquid[_qp],
                                                                  _arhoA_vapor[_qp],
                                                                  _h_liquid[_qp],
                                                                  _h_vapor[_qp],
                                                                  h_sat_liquid,
                                                                  _area[_qp]);
  }
  return quality;
}
