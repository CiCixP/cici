#ifndef ENTRAINMENTFRACTIONAUX_H
#define ENTRAINMENTFRACTIONAUX_H

#include "AuxKernel.h"
#include "Material.h"
#include "Numerics.h"
#include "TwoPhaseFluidProperties.h"
#include "SinglePhaseFluidProperties.h"
#include "FlowRegimeDependentParameters.h"

// Forward Declarations
class EntrainmentFractionAux;
class TwoPhaseFluidProperties;
class SinglePhaseFluidProperties;

template <>
InputParameters validParams<EntrainmentFractionAux>();

class EntrainmentFractionAux : public AuxKernel
{
public:
  EntrainmentFractionAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const VariableValue & _alpha_vapor;
  const VariableValue & _rho_liquid;
  const VariableValue & _rho_vapor;
  const VariableValue & _velocity_liquid;
  const VariableValue & _velocity_vapor;
  const VariableValue & _T_liquid;
  const VariableValue & _v_vapor;
  const VariableValue & _e_vapor;
  const TwoPhaseFluidProperties & _fp;
  const SinglePhaseFluidProperties & _fp_vapor;
};

#endif /* EntrainmentFractionAux_H */
