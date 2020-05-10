//Jun Yang 2020-2-20
//The program will ask for two fractions (as four integers) and will print out the sum of them.
#include <iostream>
using namespace std;
int CommonFactor(int x, int y)//Create a function to find the common factor of two integers
{
    int z = y;
    while(x%y!=0)//Keep checking if int x is divisible by int y, if they are divisible, store the factor as z and return it
    {
        z=x%y;
        x=y;
        y=z;
    }
    return z;
}
int main()
{
    int n1;//Define the first numerator
    int n2;//Define the second numerator
    int n3;//Define the final numerator
    int d1;//Define the first denominator
    int d2;//Define the second denominator
    int d3;//Define the final denominator
    int e=0;//Define the integer part of the final answer
    cout << "Input the first numerator: ";//Ask for the numerators and denominators and save them
    cin >> n1;
    cout << "Input the first denominator: ";
    cin >> d1;
    cout << "Input the second numerator: ";
    cin >> n2;
    cout << "Input the second denominator: ";
    cin >> d2;
    int CF1 = CommonFactor(n1,d1);//Simplify the first fraction, divide them by the common factor
    n1 = n1/CF1;
    d1 = d1/CF1;
    int CF2 = CommonFactor(n2,d2);//Simplify the second fraction, divide them by the common factor
    n2 = n2/CF2;
    d2 = d2/CF2;
    d3 = d1*d2;//Calculate the final denominator with the two denominators mutiply each other
    n3 = n1*d2 + n2*d1;//Calculate the final numerator by mutiplying each other
    int CF3 = CommonFactor(n3,d3);//Find the common factor of the final answer's numerator and denominator
    n3 = n3/CF3;
    d3 = d3/CF3;
    while(n3>=d3)//If the numerator is bigger than denominator, trans the extra part to a integer
    {
        n3 = n3-d3;
        e=e+1;
    }
    if(n3 == 0)//If the fraction part is 0, print the integer part only
        cout << "The sum is: " << e;
    else if(e > 0)//If the fraction part and integer part are both not 0, print both of them
        cout << "The sum is: " << e << " and " << n3 << "/" << d3;
    else if(e <= 0)//If the integer part is 0, print the fraction part only
        cout << "The sum is: " << n3 << "/" << d3;
}
