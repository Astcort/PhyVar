#include <Eigen>
#include "../include/PhyVar.hpp"
#include "../include/PhyVarEigen.hpp"


int main(int argc, char *argv[]) {

  PhyVar<double, Mass> m1(15.);
  PhyVar<double, Mass> m2(10.);
  
  std::cout << m1 << " + " << m2 << " = " << m1+m2 << std::endl;
  std::cout << m1 << " - " << m2 << " = " << m1-m2 << std::endl;
  std::cout << m1 << " * " << m2 << " = " << m1*m2 << std::endl;
  std::cout << m1 << " / " << m2 << " = " << m1/m2 << std::endl;

  Eigen::Matrix<PhyVar<double, Mass>, 2, 1> massMatrix;
  massMatrix << m1, m2;

  PhyVar<double, Newton> n1(15.);
  PhyVar<double, Newton> n2(10.);
  PhyVar<double, Newton> n3(5.);
  PhyVar<double, Newton> n4(0.);

  Eigen::Matrix<PhyVar<double, Newton>, 2, 2> newtonMatrix;
  newtonMatrix << n1, n2, n3, n4;

  auto res = newtonMatrix * massMatrix;

  std::cout << "Mult : " << res << std::endl;
  
  return 0;
}
