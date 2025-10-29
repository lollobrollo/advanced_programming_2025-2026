
#ifndef AUTODIFF_HPP
#define AUTODIFF_HPP

class ADExpression {
  public:
    virtual const double evaluate(double x) const = 0; //returns the value of the variable
    virtual const double derivative(double x) const = 0; // returns the derivative of the variable
};

class Scalar: public ADExpression { // class representing a constant scalar
  private:
    const double value;

  public:
    Scalar(double val): value(val) {};
    const double evaluate(double x) const override {
      return value;
    };
    const double derivative(double x) const override {
      return 0.0;
    }
};

class Variable: public ADExpression { //class representing a basic variable x
  public:
    const double evaluate(double x) const override {
      return x;
    };
    const double derivative(double x) const override {
      return 1.0;
    }
};

class Sum: public ADExpression{
  private:
    ADExpression* left;
    ADExpression* right;
  public:
    Sum(ADExpression* left, ADExpression* right) {
      this->left = left;
      this->right = right;
    };
    const double evaluate(double x) const override;
    const double derivative(double x) const override;
};

class Difference: public ADExpression{
  private:
    ADExpression* left;
    ADExpression* right;
  public:
    Difference(ADExpression* left, ADExpression* right) {
      this->left = left;
      this->right = right;
    };
    const double evaluate(double x) const override;
    const double derivative(double x) const override;
};

class Product: public ADExpression{
  private:
    ADExpression* left;
    ADExpression* right;
  public:
    Product(ADExpression* left, ADExpression* right) {
      this->left = left;
      this->right = right;
    };
    const double evaluate(double x) const override;
    const double derivative(double x) const override;
};

class Power: public ADExpression{
  private:
    ADExpression* base;
    ADExpression* exponent;
  public:
    Power(ADExpression* base, ADExpression* exponent) {
      this->base = base;
      this->exponent = exponent;
    };
    const double evaluate(double x) const override;
    const double derivative(double x) const override;
};

class Division: public ADExpression{
  private:
    ADExpression* left;
    ADExpression* right;
  public:
    Division(ADExpression* left, ADExpression* right) {
      this->left = left;
      this->right = right;
    };
    const double evaluate(double x) const override;
    const double derivative(double x) const override;
};


#endif