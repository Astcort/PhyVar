#include "../include/PhyVar.hpp"


int main(int argc, char *argv[]) {

  PhyVar<double, Mass> m1(10.);
  PhyVar<double, Mass> m2(15.);
  PhyVar<double, Mass> m3 = m1 + m2;
  
  std::cout << "Sum of " << m1
            << " and " << m2
            << " is " << m3 << std::endl;


  return 0;
}
