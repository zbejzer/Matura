#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <map>

#define DATA_FILE "uczniowie.txt" // uczniowie przyklad
#define DATA_SIZE 400

using namespace std;

class Student
{
public:
    array<int, 10> grades;
    string pesel, full_branch, branch;

    void updateFullBranch();
};

void Student::updateFullBranch() {
    full_branch = to_string(7 - (pesel.at(1) - '0')) + branch;
}

int main()
{
    Student current_student;
    map<string, int> students_count;
    ifstream data(DATA_FILE);

    current_student.grades = { 0 };

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        Student current_student;

        data >> current_student.pesel >> current_student.branch;

        for (size_t j = 0; j < current_student.grades.size(); j++)
        {
            data >> current_student.grades.at(j);
        }

        current_student.updateFullBranch();

        students_count[current_student.full_branch]++;
    }

    for (auto i : students_count) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}