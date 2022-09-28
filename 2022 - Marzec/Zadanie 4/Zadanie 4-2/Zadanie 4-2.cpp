#include <iostream>
#include <fstream>
#include <array>
#include <string>

#define DATA_FILE "uczniowie.txt" // uczniowie przyklad
#define DATA_SIZE 400

using namespace std;

class Student
{
public:
    array<int, 10> grades;
    string pesel, branch;
};

float avg(array<int, 10> grades) {
    int sum = 0;

    for (size_t i = 0; i < 10; i++)
    {
        sum += grades.at(i);
    }

    return sum / 10.0;
}

float avgWeighted(array<int, 10> grades) {
    int sum = 0;
    const array<int, 10> weights = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 4 };

    for (size_t i = 0; i < 10; i++)
    {
        sum += grades.at(i) * weights.at(i);
    }

    return sum / 25.0;
}

int getGrade(float avg) {
    if (avg < 1.91) {
        return 1;
    }
    else if (avg < 2.75) {
        return 2;
    }
    else if (avg < 3.75) {
        return 3;
    }
    else if (avg < 4.51) {
        return 4;
    }
    else if (avg < 5.21) {
        return 5;
    }

    return 6;
}

int main()
{
    Student current_student;
    ifstream data(DATA_FILE);
    int counter = 0;

    current_student.grades = { 0 };

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        Student current_student;

        data >> current_student.pesel >> current_student.branch;

        for (size_t j = 0; j < current_student.grades.size(); j++)
        {
            data >> current_student.grades.at(j);
        }

        if (getGrade(avgWeighted(current_student.grades)) > getGrade(avg(current_student.grades))) {
            counter++;
        }
    }

    cout << counter;

    return 0;
}