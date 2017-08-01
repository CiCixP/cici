#ifndef AECL2006CHFTABLE_H
#define AECL2006CHFTABLE_H

#include "CHFTable.h"
#include "TrilinearInterpolation.h"

class AECL2006CHFTable;

template <>
InputParameters validParams<AECL2006CHFTable>();

/**
 * AECL 2006 CHF lookup table
 *
 * Based on Groeneveld, D. C., et al. "The 2006 CHF look-up table." Nuclear Engineering and Design
 * 237.15 (2007): 1909-1922.
 */
class AECL2006CHFTable : public CHFTable
{
public:
  AECL2006CHFTable(const InputParameters & parameters);

  virtual Real chf(Real pressure, Real mass_flux, Real quality) const;
  virtual Real getMaxMassFlux() const;

protected:
  static std::vector<Real> _pressure;
  static std::vector<Real> _mass_flux;
  static std::vector<Real> _quality;
  static std::vector<Real> _chf_data;

  TrilinearInterpolation _chf_trilin;
};

#endif // AECL2006CHFTABLE_H
