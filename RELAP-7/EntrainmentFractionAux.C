#include "EntrainmentFractionAux.h"

template <>
InputParameters
validParams<EntrainmentFractionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("alpha_vapor", "Void fraction");
  params.addRequiredCoupledVar("rho_liquid", "Liquid phase density");
  params.addRequiredCoupledVar("rho_vapor", "Vapor phase density");
  params.addRequiredCoupledVar("vel_liquid", "Velocity of the liquid");
  params.addRequiredCoupledVar("vel_vapor", "Velocity of the vapor");
  params.addRequiredCoupledVar("T_liquid", "Temperature of the liquid");
  params.addRequiredCoupledVar("v_vapor", "Coupled vapor phase specific volume, aux variable");
  params.addRequiredCoupledVar("e_vapor",
                               "Coupled vapor phase specific internal energy, aux variable");
  params.addRequiredParam<UserObjectName>("fp",
                                          "The name of the 2-phase fluid properties user object");
  return params;
}

EntrainmentFractionAux::EntrainmentFractionAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _alpha_vapor(coupledValue("alpha_vapor")),
    _rho_liquid(coupledValue("rho_liquid")),
    _rho_vapor(coupledValue("rho_vapor")),
    _velocity_liquid(coupledValue("vel_liquid")),
    _velocity_vapor(coupledValue("vel_vapor")),
    _T_liquid(coupledValue("T_liquid")),
    _v_vapor(coupledValue("v_vapor")),
    _e_vapor(coupledValue("e_vapor")),
    _fp(getUserObject<TwoPhaseFluidProperties>("fp")),
    _fp_vapor(getUserObjectByName<SinglePhaseFluidProperties>(_fp.getVaporName()))
{
}

Real
EntrainmentFractionAux::computeValue()
{
  Real delta_rho = std::max(_rho_liquid[_qp] - _rho_vapor[_qp], 0.01);
  Real mu_vapor = _fp_vapor.mu(_v_vapor[_qp], _e_vapor[_qp]);
  Real surf_tension = surfaceTension(_T_liquid[_qp]);
  return FlowRegimeDependentParameters::entrainmentFractionPostCHF(surf_tension,
                                                                   _alpha_vapor[_qp],
                                                                   delta_rho,
                                                                   _rho_liquid[_qp],
                                                                   _rho_vapor[_qp],
                                                                   _velocity_liquid[_qp],
                                                                   _velocity_vapor[_qp],
                                                                   mu_vapor);
}
