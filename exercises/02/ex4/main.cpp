#include "ex4.hpp"
#include <vector>


// forward declaration (now included in header)
//void display_students(const std::vector<Student>& students);

int main() {
    std::vector<Student> students = {
        {"Alice", 20, 89.5},
        {"Bob", 21, 76.2},
        {"Charlie", 19, 92.8},
        {"Diana", 22, 85.3},
        {"Ethan", 20, 78.9}
    };

    display_students(students);
}