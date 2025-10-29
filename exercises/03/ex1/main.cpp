#include <iostream>
#include "data_processor.hpp"

int main() {
    double arr[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    const int len = 8;
    DataProcessor dp(arr, len);

    std::cout << "Min: " << dp.getMin() << '\n';
    std::cout << "Max: " << dp.getMax() << '\n';
    std::cout << "Mean: " << dp.getMean() << '\n';
    std::cout << "StdDev: " << dp.getStdDev() << '\n';

    return 0;
}

friend 