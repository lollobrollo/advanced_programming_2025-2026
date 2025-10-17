#include <iostream>
#include <string>
#include "calculator.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Opening calculator...\n";
    bool running = true;

    std::string user_input;
    char operation;

    double num1;
    double num2;
    double last_result = 0.0;

    while (running) {
        std::cout << "\nPlease choose operation by typing its first letter:\n"
                  << "Addition; Subtraction; Multiplication; Division; Exit\n> ";
        std::getline(std::cin, user_input);
        operation = user_input.empty() ? '\0' : user_input[0];

        if (operation == 'E' || operation == 'e') {
            running = false;
            continue;
        }

        // Get first number
        std::cout << "Please insert the first number (empty = last result: " 
                  << last_result << "): ";
        std::getline(std::cin, user_input);
        if (user_input.empty()) {
            num1 = last_result;
        } else {
            num1 = std::stod(user_input);
        }

        // Get second number
        std::cout << "Please insert the second number (empty = last result: " 
                  << last_result << "): ";
        std::getline(std::cin, user_input);
        if (user_input.empty()) {
            num2 = last_result;
        } else {
            num2 = std::stod(user_input);
        }

        // Perform operation
        switch (operation) {
            case 'A':
            case 'a':
                last_result = calc::addition(num1, num2);
                std::cout << num1 << " + " << num2 << " = " << last_result << "\n";
                break;
            case 'S':
            case 's':
                last_result = calc::subtraction(num1, num2);
                std::cout << num1 << " - " << num2 << " = " << last_result << "\n";
                break;
            case 'M':
            case 'm':
                last_result = calc::multiplication(num1, num2);
                std::cout << num1 << " * " << num2 << " = " << last_result << "\n";
                break;
            case 'D':
            case 'd':
                if (num2 == 0) {
                    std::cout << "Error: division by zero!\n";
                } else {
                    last_result = calc::division(num1, num2);
                    std::cout << num1 << " / " << num2 << " = " << last_result << "\n";
                }
                break;
            default:
                std::cout << "Operation not recognized, please try again.\n";
                break;
        }

        std::cout << "----------------------------------------\n";
    }

    std::cout << "Exiting program ...\n";
    return 0;
}
