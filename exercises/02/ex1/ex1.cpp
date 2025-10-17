#include <iostream>
#include <cstdlib> // for atof()

// int main(int argc, char* argv[]) {
//     std::cout << "Argument count: " << argc << "\n";
//     for (int i = 0; i < argc; ++i) {
//         std::cout << "argv[" << i << "] = " << argv[i] << "\n";
//     }
//     return 0;
// }


int main(int argc, char* argv[]) {
    float temp = std::atof(argv[1]);
    char measure = argv[2][0];

    if (measure == 'F') {
        float result = (5.0 / 9.0) * (temp - 32);
        std::cout << temp << " F = " << result << " C\n";
        return 0;

    }
    else if (measure == 'C')
    {
        float result = (9.0/5.0) * temp + 32;
        std::cout << temp << "C = " << result << "F\n";
        return 0;
    }
    else {
        std::cout << "Error: couldn't process input\n";
        return 1;
    }
}