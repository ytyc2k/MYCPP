//Jun Yang 2020-02-19
//The programe would print a calendar for one month after the user inputs an integer specifying the first day of the month and an integer specifying how many days are in a month.
#include <iostream>
#include <iomanip>
using namespace std;
void calendar(int &firstDay, int &numberOfDays)//Create a function to make a calender
{
    cout.width(5);//Align the first line with the date below
    cout << "Sun" << setw(5) << "Mon" << setw(5) << "Tue" << setw(5) <<"Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat" << endl;//Print the week
    for(int j = 1; j <= firstDay; j++)//Leave space for the first week of the month
        cout << "" << setw(5);
    for(int i = 1; i <= numberOfDays; i++)//Print all days of the month
    {
        cout << i << setw(5);
        int k = i + firstDay - 1;
        if(k%7 == 0)//Change line every 7 days
            cout << endl;
    }
}
int main()
{
    int firstDay = 0;//Set the interger of the first day
    int numberOfDays = 0;//Set the interger of the total day number
    cout << "First day of the month: ";//Ask for the first day
    cin >> firstDay;//Record the first day
    cout << "Numbers of days in the month: ";//Ask for the number of days
    cin >> numberOfDays;//Record the number of days
    calendar(firstDay, numberOfDays);//Create a calendar
}
