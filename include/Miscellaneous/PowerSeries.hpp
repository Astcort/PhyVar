#ifndef PHYVAR_POWER_SERIES_HPP
#define PHYVAR_POWER_SERIES_HPP

#include "PowerSeries.tpp"

namespace PhyV {

template <typename PhyVarType, unsigned int maxExponent>
struct PowerSeries :
    public PowerSeriesHelper<PhyVarType, maxExponent, maxExponent>::typeValue {};

} // namespace PhyV
#endif // PHYVAR_POWER_SERIES_HPP
