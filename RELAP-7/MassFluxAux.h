#ifndef MassFluxAux_H
#define MassFluxAux_H

#include "AuxKernel.h"

// Forward Declarations
class MassFluxAux;

template <>
InputParameters validParams<MassFluxAux>();

class MassFluxAux : public AuxKernel
{
public:
  MassFluxAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const VariableValue & _area;
  const VariableValue & _arhoA_liquid;
  const VariableValue & _arhoA_vapor;
  const VariableValue & _velocity_liquid;
  const VariableValue & _velocity_vapor;
};

#endif /* MassFluxAux_H */
