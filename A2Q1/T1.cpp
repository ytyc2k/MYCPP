/*
Jun Yang
2020-4-10
This project has 3 parts, to calculate a number in fibonacci, check a palindrome and check the number of McNuggets
*/
#include <iostream>
using namespace std;
int fibonacci(int n)//Create a new function
{
    int j;
    if(n > 2)
        j = fibonacci(n-1)+fibonacci(n-2);//Set the number as the sum of previous 2 numbers
    else
        j = 1;//Set the first 2 numbers as 1
    return j;//Return the number
}

bool palindrome(string s)
{
    if(s.length()<=1)//If the word only has 1 letter then see it as palindrome
        return true;
    if(s[0]!=s[s.length()-1])//Check if the word's first and last letter is the same
        return false;
    else
        s = s.substr(1,s.length()-2);//Keep checking the second and the last second letter
    return palindrome(s);
}

bool valid(int n)
{
    if(n<6)//If the number is less than 6 then it's not capable to buy
        return false;
    else if(n%20==0 || n%6==0 || n%9==0)//If the number is the multiple of 6,9 or 12 then it's capable to buy
        return true;
    else if(n>9 && n%3==0)//If the number is bigger than 9 and a multiple of 3, minus 9 and test it again
        return valid(n-9);
    else if(n>20)
        return valid(n-20);//If the number is bigger than 20 and not a multiple of 3, then minus 20 and test it again
    else
        return false;
}
int main()
{
    int num1;
    string string1;
    int num2;
    cout << "Input the sequence number in the Fibonacci sequence: ";//The first test of fibonacci
    cin >> num1;
    cout <<"The number is " << fibonacci(num1)<<endl;//Input the number into the first function and print the number in fibonacci
    cout << "Input the string to check if it is a palindrome: ";//The second test of palindrome
    cin >> string1;
    if(palindrome(string1))
        cout << "This is a palindrome!" << endl;//If it's a palindrome print it is
    else
        cout << "This is not a palindrome!" << endl;//If not, print it is not palindrome
    cout << "Input the number of McNuggets you want to purchase: ";//The thrid test of Valid
    cin >> num2;//Input the number of McNuggets
    if(valid(num2))
        cout << "These McNuggets can be purchased!";//If the number of McNuggets can be purchased, print it can be
    else
        cout << "You cannot purchase this number of McNuggets!";//If the number of McNuggets cannot be purchased, print it cannot
}
