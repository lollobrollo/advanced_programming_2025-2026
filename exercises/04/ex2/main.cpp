#include "autodiff.hpp"
#include <iostream>

int main(){
  Variable x = Variable();
  Scalar s2 = Scalar(2.0);
  Scalar s3 = Scalar(3.0);
  Scalar s4 = Scalar(4.0);
  Scalar s5 = Scalar(5.0);

  Power pow2 = Power(&x, &s2);
  Power pow3 = Power(&x, &s3);
  Product prod1 = Product(&s2, &pow3);
  Product prod2 = Product(&s3, &pow2);
  Product prod3 = Product(&s4, &x);
  Difference dif1 = Difference(&prod1, &prod2);
  Difference dif2 = Difference(&prod3, &s5);
  Sum fx = Sum(&dif1, &dif2);
  double val;
  std::cout << "Please insert where you want the function to be evaluated and derived: ";
  std::cin >> val;
  std::cout << "\nExpression f(x) evaluated in " << val << ": " << fx.evaluate(val) <<"\nAnd its derivative: " << fx.derivative(val) << "\n";
  return 1;
}