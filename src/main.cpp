#include "../include/PhyVar.hpp"
#include <Eigen>


int main(int argc, char *argv[]) {

  PhyVar<double, Mass> m1(15.);
  PhyVar<double, Mass> m2(10.);
  
  std::cout << m1 << " + " << m2 << " = " << m1+m2 << std::endl;
  std::cout << m1 << " - " << m2 << " = " << m1-m2 << std::endl;
  std::cout << m1 << " * " << m2 << " = " << m1*m2 << std::endl;
  std::cout << m1 << " / " << m2 << " = " << m1/m2 << std::endl;


  return 0;
}
