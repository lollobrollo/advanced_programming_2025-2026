#include "ex4.hpp"
#include <vector>
#include <iostream>

void display_students(const std::vector<Student>& students){
    for(const auto& s : students) {
        std::cout << "Name: " << s.name << " ; Age: " << s.age << " ; Average rank: " << s.grade_average << "\n";
    }
}