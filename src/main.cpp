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

 
}

void eigenExample() {

  
  PhyV::PhyVar<double, PhyV::Mass> m1(15.);
  PhyV::PhyVar<double, PhyV::Mass> m2(10.);
  
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

  PhyV::TimeD dt(1.e-10);
  const PhyV::TimeD tMax(0.1);

  dt = 1.e-2;

  PhyV::MassD m(0.5);

  PhyV::PositionD pos(0.);
  PhyV::VelocityD vel(0.);
  PhyV::AccelerationD acc(0.);

  PhyV::NewtonD g(-9.81);

  PhyV::TimeD t(0.);
  for(; t < tMax; t+= dt) {
    acc = m * g;
    vel += acc * dt;
    pos += vel * dt;
    std::cout << "Time : " << t << std::endl;
    std::cout << "\tPosition : " << pos << std::endl;
    std::cout << "\tVelocity : " << vel << std::endl;
  }
  
}



int main(int argc, char *argv[]) {

  basicExample();

  eigenExample();

  timeStepExample();
  
  return 0;
}
