//Jun Yang 2020-2-19
//The program would accept a sequence of words as input and respond with a single word that is composed of the first letter of each word in the input.
#include "iostream"
using namespace std;
void Acronym(string &str)//Create a string function that returns the acronym
{
    cout << str[0];//Print the first letter of the words
    for(int i = 1; i <= str.length(); i++)//Check if there's any space in the string
    {
        if(str[i] == ' ')
        {
            cout << str[i+1];//If there's a space in the string, print the letter after it
        }
    }
}
int main()
{
    string str;//Set the string you want to input
    cout << "Input: ";
    getline(cin,str);//Record the input as the string
    cout << "Acronym: ";
    Acronym(str);//Use the function to create the acronym
}
