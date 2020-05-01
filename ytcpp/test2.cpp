#include <iostream>
#include <iomanip>
using namespace std;
void cincheck(){
    if (cin.fail())
    {
        cout << "Please select again! " << '\n';
        cin.clear();
        cin.ignore(1024, '\n');
        return 1;   
    }
    else
    {
        return 0;
    }
    
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
        int input=0; //Ask for the user's input
        cincheck();
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "hello1" <<endl;
            break;
        case 2:
            cout << "hello2" <<endl;
            break;
        case 7:
            cout << "Quit" <<endl;
            goto exit_loop;
        default:
            goto exit_loop;
        }
    }
    exit_loop:;
}