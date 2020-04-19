#include <iostream>
using namespace std;
bool cube(int n)
{
    int a,b,c,T;
    if(n>=100)
    {
        a=n/100;
        b=n/10%10;
        c=n%10;
        T=a*a*a+b*b*b+c*c*c;
        if(T==n)
        {
            return true;
        }
        else
            return false;
    }
    else if(n==1)
    {
        return true;
    }
}


int main()
{
    /*Part A
    int a,b,c,S,T;
    while(1)
    {
        cout << "Input an integer: ";
        cin >> S;
        if(S>=100)
        {
            a=S/100;
            b=S/10%10;
            c=S%10;
            T=a*a*a+b*b*b+c*c*c;
            cout << "The sum of the cubes is " << T <<endl;
            cout <<endl;
        }
        else
        {
            cout << "Bye!";
            break;
        }
    }
    */

    /*Part B
    int a,b,c;
    for(int i=1; i<=99;i++)
    {
        a=i/10;
        b=i%10;
        if(a*a*a+b*b*b==i)
            cout << i << endl;
    }
    for(a=1; a<=9; a++)
    {
        for(b=0; b<=9; b++)
        {
            for(c=0; c<=9; c++)
            {
                if(a*100+b*10+c==a*a*a+b*b*b+c*c*c)
                {
                    cout << a << b<<c<<endl;
                }
            }
        }
    }
    */

    /*Part C
    if(cube(371))
    {
        cout << "yes";
    }
    */
}
