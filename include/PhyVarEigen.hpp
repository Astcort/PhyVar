#ifndef PHYVAR_EIGEN_HPP
#define PHYVAR_EIGEN_HPP

#include <Eigen>
#include "PhyVar.hpp"

namespace Eigen {

template<>
template<typename NumType, typename UnitType>
struct ScalarBinaryOpTraits<PhyVar<NumType, UnitType>,
                            PhyVar<NumType, UnitType>,
                            internal::scalar_sum_op<PhyVar<NumType, UnitType>,
                                                    PhyVar<NumType, UnitType> > >
{
  typedef PhyVar<NumType, UnitType> ReturnType;
};


template<>
template<typename NumType, typename UnitType>
struct ScalarBinaryOpTraits<PhyVar<NumType, UnitType>,
                            PhyVar<NumType, UnitType>,
                            internal::scalar_difference_op<PhyVar<NumType, UnitType>,
                                                           PhyVar<NumType, UnitType> > >
{
  typedef PhyVar<NumType, UnitType> ReturnType;
};


template<>
template<typename NumType, typename UnitType1, typename UnitType2>
struct ScalarBinaryOpTraits<PhyVar<NumType, UnitType1>,
                            PhyVar<NumType, UnitType2>,
                            internal::scalar_product_op<PhyVar<NumType, UnitType1>,
                                                        PhyVar<NumType, UnitType2>> >
{
  typedef PhyVar<NumType,
                 Unit <UnitType1::kg + UnitType2::kg,
                       UnitType1::m  + UnitType2::m,
                       UnitType1::s  + UnitType2::s> > ReturnType;
};

template<>
template<typename NumType, typename UnitType1, typename UnitType2>
struct ScalarBinaryOpTraits<PhyVar<NumType, UnitType1>,
                            PhyVar<NumType, UnitType2>,
                            internal::scalar_quotient_op<PhyVar<NumType, UnitType1>,
                                                        PhyVar<NumType, UnitType2>> >
{
  typedef PhyVar<NumType,
                 Unit <UnitType1::kg - UnitType2::kg,
                       UnitType1::m  - UnitType2::m,
                       UnitType1::s  - UnitType2::s> > ReturnType;
};

} //namespace Eigen
  
#endif //PHYVAR_EIGEN_HPP
