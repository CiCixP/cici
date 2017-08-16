#include "MassFluxAux.h"

template <>
InputParameters
validParams<MassFluxAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("arhoA_liquid", "Liquid mass equation variable: alpha*rho*A");
  params.addRequiredCoupledVar("arhoA_vapor", "Vapor mass equation variable: alpha*rho*A");
  params.addRequiredCoupledVar("vel_liquid", "Velocity of the liquid");
  params.addRequiredCoupledVar("vel_vapor", "Velocity of the vapor");
  params.addRequiredCoupledVar("A", "Cross-sectional area");
  return params;
}

MassFluxAux::MassFluxAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _area(coupledValue("A")),
    _arhoA_liquid(coupledValue("arhoA_liquid")),
    _arhoA_vapor(coupledValue("arhoA_vapor")),
    _velocity_liquid(coupledValue("vel_liquid")),
    _velocity_vapor(coupledValue("vel_vapor"))
{
}

Real
MassFluxAux::computeValue()
{
  return (_arhoA_liquid[_qp] * _velocity_liquid[_qp] + _velocity_vapor[_qp] * _arhoA_vapor[_qp]) /
         _area[_qp];
}
