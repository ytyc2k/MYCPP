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
    int a=20;
    int i = 0;
    int k = i+++5;
    cout << k << endl;
    cout << i << endl;
    if(a-- ==19)
    {
        cout << "!!!";
    }
     
     cout << string(30, 'I') << endl;
}