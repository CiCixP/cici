#ifndef HSATLIQAUX_H
#define HSATLIQAUX_H

#include "AuxKernel.h"
#include "FlowRegimeDependentParameters.h"
#include "TwoPhaseFluidProperties.h"
#include "SinglePhaseFluidProperties.h"

// Forward Declarations
class HSatLiqAux;
class TwoPhaseFluidProperties;
class SinglePhaseFluidProperties;

template <>
InputParameters validParams<HSatLiqAux>();

class HSatLiqAux : public AuxKernel
{
public:
  HSatLiqAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const VariableValue & _p_liquid;
  const TwoPhaseFluidProperties & _fp;
  const SinglePhaseFluidProperties & _fp_liquid;
};

#endif /* HSATLIQAUX_H */
