#ifndef QUALITYAUX_H
#define QUALITYAUX_H

#include "AuxKernel.h"
#include "FlowRegimeDependentParameters.h"
#include "TwoPhaseFluidProperties.h"
#include "SinglePhaseFluidProperties.h"

// Forward Declarations
class QualityAux;
class TwoPhaseFluidProperties;
class SinglePhaseFluidProperties;

template <>
InputParameters validParams<QualityAux>();

class QualityAux : public AuxKernel
{
public:
  QualityAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const VariableValue & _area;
  const VariableValue & _arhoA_liquid;
  const VariableValue & _arhoA_vapor;
  const VariableValue & _h_liquid;
  const VariableValue & _h_vapor;
  const VariableValue & _velocity_liquid;
  const VariableValue & _velocity_vapor;
  const VariableValue & _p_liquid;
  const TwoPhaseFluidProperties & _fp;
  const SinglePhaseFluidProperties & _fp_liquid;
};

#endif /* QUALITYAUX_H */
