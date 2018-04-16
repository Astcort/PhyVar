#include <tuple>

namespace PhyV {

template <typename PhyVarType, unsigned int power>
struct PhyVarPowerHelper {
  using typeValue = PhyVar<typename PhyVarType::NumType,
                           Unit<PhyVarType::UnitType::kg * power,
                                PhyVarType::UnitType::m  * power,
                                PhyVarType::UnitType::s  * power> >;
};


template <typename PhyVarType,
          unsigned int curExponent,
          unsigned int maxExponent,
          typename... powers>
struct PowerSeriesHelperIter
{
  using typeValue = typename PowerSeriesHelperIter<PhyVarType,
                                                   curExponent - 1u,
                                                   maxExponent,
                                                   typename PhyVarPowerHelper<PhyVarType, curExponent>::typeValue,
                                                   powers...
                                                   >::typeValue;
};

  
  
template <typename PhyVarType,
          unsigned int maxExponent,
          typename... powers>
struct PowerSeriesHelperIter<PhyVarType, 0u, maxExponent, powers...>
{
  using typeValue = std::tuple<powers...>;
};



template <typename PhyVarType,
          unsigned int curExponent,
          unsigned int maxExponent>
struct PowerSeriesHelper
{
  using typeValue = typename PowerSeriesHelperIter<PhyVarType,
                                                   curExponent - 1u,
                                                   maxExponent,
                                                   typename PhyVarPowerHelper<PhyVarType, curExponent>::typeValue
                                                   >::typeValue;
};




} // namespace PhyV
