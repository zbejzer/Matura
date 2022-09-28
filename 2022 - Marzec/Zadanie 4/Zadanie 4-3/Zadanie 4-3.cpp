#include <iostream>
#include <array>
#include <math.h>
#include <string>
#include <fstream>

#define DATA_FILE "uczniowie.txt" // uczniowie przyklad
#define DATA_SIZE 400

using namespace std;

class Student
{
public:
    array<int, 10> grades;
    string pesel;
    char branch;

    int grade7System();
};

int Student::grade7System()
{
    int sum = 0;

    for (size_t i = 0; i < grades.size(); i++)
    {
        sum += pow(6, grades.size() - 1 - i) * grades.at(i);
    }

    return sum;
}

int main()
{
    Student max_student;
    ifstream data(DATA_FILE);

    max_student.grades = {0};

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        Student current_student;

        data >> current_student.pesel >> current_student.branch;

        for (size_t j = 0; j < current_student.grades.size(); j++)
        {
            data >> current_student.grades.at(j);
        }

        if (current_student.grade7System() % 5 == 0 && current_student.grade7System() > max_student.grade7System()) {
            max_student = current_student;
        }
    }

    cout << max_student.pesel;

    return 0;
}