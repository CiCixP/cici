#include "HSatLiqAux.h"

template <>
InputParameters
validParams<HSatLiqAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("p_liquid", "Pressure of the liquid phase");
  params.addRequiredParam<UserObjectName>("fp",
                                          "The name of the 2-phase fluid properties user object");
  return params;
}

HSatLiqAux::HSatLiqAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _p_liquid(coupledValue("p_liquid")),
    _fp(getUserObject<TwoPhaseFluidProperties>("fp")),
    _fp_liquid(getUserObjectByName<SinglePhaseFluidProperties>(_fp.getLiquidName()))
{
}

Real
HSatLiqAux::computeValue()
{
  Real p_liquid = _p_liquid[_qp];
  // ensure pressure is positive
  if (p_liquid < 1.0e-5)
    p_liquid = 1.0e-5;
  Real T_sat = _fp.T_sat(p_liquid);
  return _fp_liquid.h(p_liquid, T_sat);
}
