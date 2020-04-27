/*
Jun Yang
2020-4-17
This is student management system in order to save and change the records of students
*/
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
 //Ask for the user's input
int input = 0;
int NumInput(){
    cin >> input;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout << "Error: Please input a correct number." << endl;
        cin >> input;
    } 
    return input;
}
int main()
{
    int opend = 0;
    while (1) //Keep showting the menu for 7 options
    {
        cout << "" << endl;
        cout << "1) Open a class from a file" << endl;
        cout << "2) Add a new student" << endl;
        cout << "3) Change existing student" << endl;
        cout << "4) Delete a student" << endl;
        cout << "5) Print a class list (include the class average)" << endl;
        cout << "6) Save the class to a file" << endl;
        cout << "7) Quit" << endl;
        cout << "" << endl;

        NumInput();
        if ( input== 1 && ++opend == 1) //Open a class from a file, and it can only open once
        {
            ifstream InFile("StudentsRecords.txt", ios::in); //Open the file
            if (!InFile.is_open())                           //Show error if it can't be open
            {
                cout << "Error: opening file fail" << endl;
                continue;
            }
            InFile.seekg(0, ios::end); //Show error if it open a empty file.
            if (!InFile.tellg())
            {
                cout << "No records in the file." << endl;
                InFile.close();
                continue;
            }
            InFile.seekg(0, ios::beg);
            struct student tmpstu; //Create an temp structure and initialize it
            while (!InFile.eof())  //Read the data from the file
            {
                InFile >> tmpstu.name >> tmpstu.number >> tmpstu.id; //Save the data into vectors
                for (int i = 0; i < tmpstu.number; i++)
                {
                    tmpstu.ks.push_back({"", 0.00});
                    InFile >> tmpstu.ks[i].CourseName >> tmpstu.ks[i].mark;
                }
                Class.push_back(tmpstu); //Save the temp structure into class vector
            }
            InFile.close();
            Class.pop_back(); //Delete the last repeated student
            cout << "Done" << endl;
        }
        else if (input == 1 && opend >= 1) //Gice an error if the file opened twice
        {
            cout << "Error: cannot open file twice" << endl;
        }
        else if (input == 2) //Add a new student
        {
            struct student tmpstu;                                            //Save the data into student's structure
            cout << "Input the student's name, course number and id" << endl; //Ask for the student's information
            cin >> tmpstu.name;
            tmpstu.number =NumInput();
            cin>> tmpstu.id;
            for (int i = 0; i < tmpstu.number; i++) //Keep asking for the student's course information
            {
                cout << "Input the course name and mark" << endl;
                tmpstu.ks.push_back({"", 0.00});
                cin >> tmpstu.ks[i].CourseName >> tmpstu.ks[i].mark;
            }
            Class.push_back(tmpstu); //Save the student's structure into the class vector
        }
        else if (input == 3) //Change existing student
        {
            if (Class.size()==0)
            {
                cout << "No records to change. Please open a class from a file, or add a new student." << endl;
                continue;
            }
            cout << "Input the student's number in the list to change the student (Ex. to change the first student, input 1)" << endl; //Ask for the student to change
            if (Class.size() < NumInput())
            {
                cout << "Over students numbers." << endl;
                continue;
            }
            cout << "Reinput the student's name, course number and id to change them" << endl; //Reset the information of the student
            cin >> Class[input - 1].name >> Class[input - 1].number >> Class[input - 1].id;
            Class[input - 1].ks.clear();                      //Clear the old course information
            for (int i = 0; i < Class[input - 1].number; i++) //Reset the course name and mark of the student
            {
                cout << "Input the course name and mark" << endl;
                Class[input - 1].ks.push_back({"", 0.00}); //Save the new information into class vector
                cin >> Class[input - 1].ks[i].CourseName >> Class[input - 1].ks[i].mark;
            }
        }
        else if (input == 4) //Delete a student
        {
            if (Class.size() == 0)
            {
                cout << "No records to delete. Please open a class from a file, or add a new student." << endl;
                continue;
            }
            cout << "Input the student's number in the list to delete the student (Ex. to change the first student, input 1)" << endl; //Ask the student to delete
            if (Class.size() < NumInput())
            {
                cout << "Over students numbers." << endl;
                continue;
            }
            Class.erase(Class.begin() + input - 1); //Delete the last student
        }
        else if (input == 5) //Print a class list
        {
            if (Class.size() == 0)
            {
                cout << "No records to print. Please open a class from a file, or add a new student." << endl;
                continue;
            }
            float Avmark = 0;
            float number = 0;
            int Size = Class.size();
            for (int i = 0; i < Size; i++) //Check every student in the class
            {
                float StudentAvmark = 0;
                for (int j = 0; j < Class[i].number; j++) //Record every student's every course's mark
                {
                    Avmark = Avmark + Class[i].ks[j].mark;
                    StudentAvmark = StudentAvmark + Class[i].ks[j].mark;
                }
                number = number + Class[i].number;
                cout << Class[i].name << "\t" << Class[i].id << "\t" << StudentAvmark / Class[i].number << endl; //Print the students' name and ID.
            }
            cout << "The class average mark is " << setiosflags(ios::fixed) << setprecision(1) << Avmark / number << endl; //Print the average mark with one decimal
        }
        else if (input == 6) //Save the class to a file
        {
            if (Class.size() == 0)
            {
                cout << "No records to save. Please open a class from a file, or add a new student." << endl;
                continue;
            }
            ofstream OutFile("StudentsRecords.txt", ios::out);
            for (int i = 0; i < Class.size(); i++) //Save every student in the class into the file
            {
                OutFile << Class[i].name << "\t" << Class[i].number << "\t" << Class[i].id << "\t";
                for (int j = 0; j < Class[i].number; j++) //For each student save their course name and mark into the file
                {
                    OutFile << Class[i].ks[j].CourseName << "\t" << Class[i].ks[j].mark << "\t";
                }
                OutFile << endl;
            }
            OutFile.close();
            cout << "Done" << endl;
        }
        else if (input =7) //Quit the program
            break;

        else
        {
            cout << "Please chose number from 1 to 7. " << endl;
            continue;
        }
    }
}
