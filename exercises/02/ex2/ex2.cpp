#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time() to seed the random generator

void findMinMax(int* arr, int size, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid size.\n";
        return 1;
    }

    int* arr = new int[size];

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    int minVal, maxVal;

    findMinMax(arr, size, minVal, maxVal);

    std::cout << "Minimum value: " << minVal << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;

    delete[] arr;

    return 0;
}
