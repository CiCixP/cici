#ifndef CRITICALHEATFLUXAUX_H
#define CRITICALHEATFLUXAUX_H

#include "AuxKernel.h"
#include "CHFTable.h"
#include "FlowRegimeDependentParameters.h"
#include "TwoPhaseFluidProperties.h"
#include "SinglePhaseFluidProperties.h"
#include "WallHeatTransferModels.h"

// Forward Declarations
class CriticalHeatFluxAux;
class TwoPhaseFluidProperties;
class SinglePhaseFluidProperties;
class CHFTable;

template <>
InputParameters validParams<CriticalHeatFluxAux>();

class CriticalHeatFluxAux : public AuxKernel
{
public:
  CriticalHeatFluxAux(const InputParameters & parameters);

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
  const CHFTable & _chf_table;
};

#endif /* CRITICALHEATFLUXAUX_H */
