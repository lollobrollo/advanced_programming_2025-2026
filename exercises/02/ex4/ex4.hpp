#ifndef EX4_HPP
#define EX4_HPP
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    double grade_average;
};

void display_students(const std::vector<Student>& students);

#endif