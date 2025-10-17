#include "statistics.hpp"
#include <algorithm> // for sorting
#include <cmath> // for rounding

namespace stat {
// Function to calculate the mean of a set of numbers.
double calculate_mean(const std::vector<double> &numbers) {
  double tmp = 0;
  for(double num : numbers){
    tmp += num;
  }
  return tmp/dim;
}

// Function to calculate the median of a set of numbers.
double calculate_median(const std::vector<double> &numbers) {
  std::sort(numbers.begin(), numbers.end());
  int median_idx = std::ceil(numbers.size() / 2.0);
  return numbers[median_idx];
}

// Function to calculate the standard deviation of a set of numbers.
double calculate_standard_deviation(const std::vector<double> &numbers) {
  double mean = calculate_mean(numbers);
  double var = 0;
  for(double num:numbers){
    var += std::pow(num - mean, 2);
  }
  return std::sqrt(var / (numbers.size()));
}
} // namespace stat
