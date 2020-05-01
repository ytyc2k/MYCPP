#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
struct course //Create a course structure for every course
{
    string CourseName;
    float mark;
};
struct student //Create a student structure for every student
{
    string name;
    int number;
    string id;
    vector<course> ks; //Create a vector for the different courses a student may have
};
vector<student> Class; //Create a class vector to hold every student

int main()
{
    struct student stu;
    stu.ks.resize(1);
    string line;
    ifstream in("../A2Q3/StudentsRecords.txt");
    while (getline(in, line,' '))
    {
   
            line >> stu.name >> stu.number >> stu.id >> stu.ks[0].CourseName >> stu.ks[0].mark;
            cout << stu.name;
    }
    
}