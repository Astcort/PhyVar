#include <iostream>
#include <type_traits>
#include <string>
#include <sstream>


/**
 * @brief Base class for the unit type
 *        Used only for type checking
 */
struct UnitBase
{
protected:
  /**
   * @brief Protected constructor
   *        No reason to instantiate this class
   */
  UnitBase() {}
};

/**
 * @brief Type checking for the Unit class
 *        Static value is obtained with isUnit<T>::value
 * 
 * @tparam T  Type to check
 */ 
template<typename T>
using isUnit = std::is_base_of<UnitBase,T>;



/**
 * @brief Unit type definition
 *
 * @tparam kgExp  Exponent for the kilogram unit
 * @tparam mExp   Exponent for the meter    unit
 * @tparam sExp   Exponent for the second   unit
 */

template <int kgExp, int mExp, int sExp>
struct Unit : public UnitBase
{

public:
  static const int kg = kgExp; /// @brief  kilogram exponent
  static const int m  = mExp;  /// @brief  meter    exponent
  static const int s  = sExp;  /// @brief  second   exponent

  /**
   * @brief Streaming operator
   *        Usage : ... << Unit::toString << ...
   * 
   * @param ostream  Output stream
   *
   * @return Output stream
   */
  static std::ostream& toString(std::ostream& out) {
    std::stringstream ss;
    printSym(kg, "kg", ss);
    printSym(m, "m", ss);
    printSym(s, "s", ss);
    out << ss.str();
    return out;
  }
protected:
  /**
   * @brief  Protected constructor
   */
  Unit() {}

  /**
   * @brief Exponent printing
   * 
   * @param exponent  Exponent
   * @param sym       Symbol
   * @param ss        String stream
   */
  static void printSym(int exponent, std::string symbol,
                       std::stringstream& ss) {
    if(exponent != 0) {
      ss << symbol;
      if (exponent != 1) {
        ss <<"^" << exponent << " ";
      }
    }
  }
};
