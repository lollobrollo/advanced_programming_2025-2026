#pragma once
#define NEWTON_TPL_HPP

//#include "newton.hpp"
#include <cmath>
#include <limits>
#include <functional>
#include <complex>

template<typename T> NewtonSolver<T>::NewtonSolver(
                           const std::function<T(const T&)> &f,
                           const std::function<T(const T&)> &df,
                           const T &x0, const double &tolerance,
                           const unsigned int &max_iterations)
    : f(f), df(df), x0(x0), tolerance(tolerance),
      max_iterations(max_iterations) {}

template<typename T> T NewtonSolver<T>::solve() {
  T x_old = x0;
  T x_new = x_old;
  unsigned int it = 0;

  while (it < max_iterations) {
    // Update x.
    const T d = this->f(x_old) / this->df(x_old); 
    x_new = x_old - d;

    // Check convergence.
    if(std::abs(d) < this->tolerance) {
      return x_new;
    };
    x_old = x_new;
    ++it;

  }

  // Indicates failure to converge.
  return std::numeric_limits<T>::quiet_NaN();
}

// template class NewtonSolver<double>;
// template class NewtonSolver<std::complex<double>>;
