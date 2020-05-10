/*
Jun Yang
2020-4-17
This is student management system in order to save and change the records of students
*/
#include  <string>
#include  <iostream>
#include  <fstream>
#include <vector>
#include <iomanip>
using namespace std;
struct course//Create a course structure for every course
{
    string CourseName;
    float mark;
};
struct student//Create a student structure for every studentwwx
{
    string name;
    int number;
    string id;
    vector<course> ks;//Create a vector for the different courses a student may have
};
vector<student> Class;//Create a class vector to hold every student
int main()
{
    int opend=0;
    while (1)//Keep showting the menu for 7 options
    {
        cout << "" <<endl;
        cout << "1) Open a class from a file(can't open it twice)" << endl;
        cout << "2) Add a new student" << endl;
        cout << "3) Change existing student" << endl;
        cout << "4) Delete a student" << endl;
        cout << "5) Print a class list (include the class average)" << endl;
        cout << "6) Save the class to a file" << endl;
        cout << "7) Quit" << endl;
        cout << "" <<endl;
        int input=0;//Ask for the user's input
        cin >> input;
        if(cin.fail())
        {
            cout<<"Please select again! "<<'\n';
            cin.clear();
            cin.ignore(1024,'\n');
        }
        if (input == 1 && ++opend==1)//Open a class from a file, and it can only open once
        {
            ifstream InFile("StudentsRecords.txt",ios::in);//Open the file
            if(!InFile.is_open())//Show error if it can't be open
            {
                cout << "Error: opening file fail" << endl;
                continue;
            }
            struct student tmpstu;//Create an temp structure and initialize it
            while(!InFile.eof()) //Read the data from the file
            {
                InFile >> tmpstu.name >> tmpstu.number >> tmpstu.id;//Save the data into vectors
                for(int j=0; j<tmpstu.number; j++)
                {
                    tmpstu.ks.push_back({"",0});
                    InFile >> tmpstu.ks[j].CourseName;
                    InFile >> tmpstu.ks[j].mark;
                }
                Class.push_back(tmpstu);//Save the temp structure into class vector
            }
            InFile.close();
            Class.pop_back();//Delete the last repeated student
            cout << "Done" << endl;
        }
        else if(input == 1 && ++opend!=1)//Gice an error if the file opened twice
            cout << "Error: cannot open file twice" << endl;
        else if (input == 2)//Add a new student
        {
            string name;
            int number=0;
            string id;
            cout <<"Input the student's name, course number and id" << endl;//Ask for the student's information
            cin >> name >> number >> id;
            struct student stu0;//Save the data into student's structure
            stu0.name=name;
            stu0.number=int(number);
            stu0.id=id;
            string CourseName;
            float mark=0;
            for (int i=0; i<number; i++)//Keep asking for the student's course information
            {
                cout << "Input the course name and mark" << endl;
                cin >> CourseName >> mark;
                stu0.ks.push_back({CourseName,mark});
            }
            Class.push_back(stu0);//Save the student's structure into the class vector
        }
        else if (input == 3)//Change existing student
        {
            string name;
            int number;
            string id;
            float mark;
            string CourseName;
            cout << "Input the student's number in the list to change the student (Ex. to change the first student, input 1)" << endl;//Ask for the student to change
            cin >> input;
            cout << "Reinput the student's name, course number and id to change them"<<endl;//Reset the information of the student
            cin >> name >> number >> id;
            Class[input-1].name=name;
            Class[input-1].number=number;
            Class[input-1].id=id;
            Class[input-1].ks.clear();//Clear the old course information
            for (int i =1; i<=number; i++)//Reset the course name and mark of the student
            {
                cout << "Input the course name and mark" << endl;
                cin >> CourseName >> mark;
                Class[input-1].ks.push_back({CourseName,mark});//Save the new information into class vector
            }
        }
        else if (input == 4)//Delete a student
        {
            cout << "Input the student's number in the list to delete the student (Ex. to change the first student, input 1)" << endl;//Ask the student to delete
            cin >> input;
            swap(Class[input-1],Class[Class.size()-1]);//Change the student to the last one
            Class.pop_back();//Delete the last student
        }
        else if (input == 5)//Print a class list
        {
            float Avmark=0;
            float number=0;
            int Size = Class.size();
            for(int i=0; i<Size; i++)//Check every student in the class
            {
                float StudentAvmark=0;
                for(int j=0; j<Class[i].number; j++)//Record every student's every course's mark
                {
                    Avmark=Avmark+Class[i].ks[j].mark;
                    StudentAvmark=StudentAvmark+ Class[i].ks[j].mark;
                }
                number = number+Class[i].number;
                cout << Class[i].name <<"\t" <<  Class[i].id << "\t"<< StudentAvmark/Class[i].number<<endl;//Print the students' name and ID.
            }
            cout << "The class average mark is " << setiosflags(ios::fixed)<<setprecision(1)<< Avmark/number << endl;//Print the average mark with one decimal
        }
        else if (input == 6)//Save the class to a file
        {
            ofstream OutFile("StudentsRecords.txt",ios::out);
            for(int i=0; i<Class.size(); i++)//Save every student in the class into the file
            {
                OutFile << Class[i].name << "\t";
                OutFile << Class[i].number << "\t";
                OutFile << Class[i].id << "\t";
                for(int j=0; j<Class[i].number; j++)//For each student save their course name and mark into the file
                {
                    OutFile << Class[i].ks[j].CourseName << "\t";
                    OutFile << Class[i].ks[j].mark << "\t";
                }
                OutFile << endl;vector<student> Class;
            }
            OutFile.close();
            cout << "Done"<<endl;
        }
        else if (input == 7)//Quit the program
            break;
    }
}
