#include "autodiff.hpp"
#include<cmath>

/* IMPLEMENTATIONS OF 'evaluate()' AND 'derivative()' FOR OPERATION CLASSES */

/* SUM */
const double Sum::evaluate(double x) const {
  return this->left->evaluate(x) + this->right->evaluate(x);
};
const double Sum::derivative(double x) const {
  return this->left->derivative(x) + this->right->derivative(x);
};

/* DIFFERENCE */
const double Difference::evaluate(double x) const {
  return this->left->evaluate(x) - this->right->evaluate(x);
};
const double Difference::derivative(double x) const {
  return this->left->derivative(x) - this->right->derivative(x);
};

/* PRODUCT */
const double Product::evaluate(double x) const {
  return this->left->evaluate(x) * this->right->evaluate(x);
};
const double Product::derivative(double x) const {
  return this->left->derivative(x) * this->right->evaluate(x) + this->left->evaluate(x) * this->right->derivative(x);
};

/* POWER */
const double Power::evaluate(double x) const{
  return std::pow(this->base->evaluate(x), this->exponent->evaluate(x));
};
const double Power::derivative(double x) const {
  const double b = this->base->evaluate(x);
  const double n = this->exponent->evaluate(x);
  const double db = this->base->derivative(x);
  return n * std::pow(b, n - 1.0) * db;
};

/* DIVISION */
const double Division::evaluate(double x) const {
  return this->left->evaluate(x) / this->right->evaluate(x);
};
const double Division::derivative(double x) const {
  Scalar s2(2.0);
  Power denom(this->right, &s2);
  return (this->left->derivative(x) * this->right->evaluate(x) - this->left->evaluate(x) * this->right->derivative(x)) / denom.evaluate(x);
};