#include "CriticalHeatFluxAux.h"

template <>
InputParameters
validParams<CriticalHeatFluxAux>()
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
  params.addParam<UserObjectName>("chf_table",
                                  "The name of the user object name with critical heat flux table");
  return params;
}

CriticalHeatFluxAux::CriticalHeatFluxAux(const InputParameters & parameters)
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
    _fp_liquid(getUserObjectByName<SinglePhaseFluidProperties>(_fp.getLiquidName())),
    _chf_table(getUserObject<CHFTable>("chf_table"))
{
}

Real
CriticalHeatFluxAux::computeValue()
{
  Real p_liquid = _p_liquid[_qp];
  // ensure pressure is positive
  if (p_liquid < 1.0e-5)
    p_liquid = 1.0e-5;
  Real T_sat = _fp.T_sat(p_liquid);
  Real h_sat_liquid = _fp_liquid.h(p_liquid, T_sat);

  Real x_static = FlowRegimeDependentParameters::getStaticFlowQuality(_arhoA_liquid[_qp],
                                                                      _arhoA_vapor[_qp],
                                                                      _h_liquid[_qp],
                                                                      _h_vapor[_qp],
                                                                      h_sat_liquid,
                                                                      _area[_qp]);
  return WallHeatTransfer::getQChf(_chf_table,
                                   p_liquid,
                                   _velocity_liquid[_qp],
                                   _velocity_vapor[_qp],
                                   _arhoA_liquid[_qp],
                                   _arhoA_vapor[_qp],
                                   _h_liquid[_qp],
                                   _h_vapor[_qp],
                                   h_sat_liquid,
                                   _area[_qp],
                                   x_static);
}
