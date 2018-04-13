#include <Eigen>
#include "../include/PhyVar.hpp"
#include "../include/PhyVarEigen.hpp"

void basicExample() {

  PhyV::PhyVar<double, PhyV::Mass> m1(15.);
  PhyV::PhyVar<double, PhyV::Mass> m2(10.);
  
  std::cout << m1 << " + " << m2 << " = " << m1+m2 << std::endl;
  std::cout << m1 << " - " << m2 << " = " << m1-m2 << std::endl;
  std::cout << m1 << " * " << m2 << " = " << m1*m2 << std::endl;
  std::cout << m1 << " / " << m2 << " = " << m1/m2 << std::endl;

  Eigen::Matrix<PhyV::PhyVar<double, PhyV::Mass>, 2, 1> massMatrix;
  massMatrix << m1, m2;

  PhyV::PhyVar<double, PhyV::Newton> n1(15.);
  PhyV::PhyVar<double, PhyV::Newton> n2(10.);
  PhyV::PhyVar<double, PhyV::Newton> n3(5.);
  PhyV::PhyVar<double, PhyV::Newton> n4(0.);

  Eigen::Matrix<PhyV::PhyVar<double, PhyV::Newton>, 2, 2> newtonMatrix;
  newtonMatrix << n1, n2, n3, n4;

  auto res = newtonMatrix * massMatrix;

  std::cout << "Mult : " << res << std::endl;

}

void timeStepExample() {

  const PhyV::TimeD dt(1.e-2);
  const PhyV::TimeD tMax(1.);

}



int main(int argc, char *argv[]) {

  return 0;
}
