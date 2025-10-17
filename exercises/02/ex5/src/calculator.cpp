#include "calculator.hpp"

namespace calc {
double addition(const double& num1, const double& num2){
  double res = num1 + num2;
  return res;
}

double subtraction(const double& num1, const double& num2){
  double res = num1 - num2;
  return res;
}

double multiplication(const double& num1, const double& num2){
  double res = num1 * num2;
  return res;
}

double division(const double& num1, const double& num2){
  double res = num1 / num2;
  return res;
}
}