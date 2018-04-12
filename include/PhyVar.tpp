#include <type_traits>

#include "Unit.tpp"


/**
 * @brief Macro to check the num type compatibility
 */
#define CHECK_NUM_TYPE(PhyVar1, PhyVar2) \
  static_assert(std::is_same<PhyVar1::NumType, PhyVar2::NumType>::value,\
                "PhyVar - Error : not the same numerical types")
/**
 * @brief Macro to check the unit type compatibility
 */
#define CHECK_UNIT_TYPE(PhyVar1, PhyVar2) \
  static_assert(std::is_same<PhyVar1::UnitType, PhyVar2::UnitType>::value,\
                "PhyVar - Error : incompatible units")


/**
 * @brief Base for the physical variable type
 */
struct PhyVarBase
{
protected:
  PhyVarBase() {}
};

/**
 * @brief Physical variable
 *        Consists in a value and a unit
 */
template <typename NumTypeIn, typename UnitTypeIn>
struct PhyVar : PhyVarBase {

public:

  using NumType  = NumTypeIn;
  using UnitType = UnitTypeIn;

  /**
   * @brief Constructor
   *
   * @param val  Value of the variable
   */
  PhyVar(NumType val) :
    m_val(val) {
    static_assert(isUnit<UnitType>::value, "PhyVar - Error : Invalid unit type");
  }


  /**
   * @brief Cast to num type
   */
  operator NumTypeIn() { return m_val; }

  /**
   * @brief Addition
   *
   * @param otherPhyVar  Other operand
   *
   * @return Sum of the two PhyVar
   */
  PhyVar<NumTypeIn, UnitTypeIn>
  operator+(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar);

  /**
   * @brief In-place addition
   *
   * @param otherPhyVar  Other operand
   *
   * @return Current PhyVar
   */
  PhyVar<NumTypeIn, UnitTypeIn>&
  operator+=(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar);
  
  /**
   * @brief Ostream operator
   *
   * @tparam NumTypeOther   Num type of the PhyVar
   * @tparam UnitTypeOther  Unit type of the PhyVar
   *
   * @param out  Output stram
   * @param var  The PhyVar to output
   *
   * @return The outpout stream
   */
  template <typename NumTypeOther, typename UnitTypeOther>
  friend std::ostream& operator<<(std::ostream &out,
                                  const PhyVar<NumTypeOther, UnitTypeOther> &var);
  
private:

  NumType m_val;
  
};


template <typename NumTypeOther, typename UnitTypeOther>
std::ostream& operator<<(std::ostream &out,
                         const PhyVar<NumTypeOther, UnitTypeOther> &var) {
  std::stringstream ss;
  ss << var.m_val << UnitTypeOther::toString;
  out << ss.str();
  return out;
}


#include "PhyVar.impl.tpp"

#undef CHECK_NUM_TYPE
#undef CHECK_UNIT_TYPE
