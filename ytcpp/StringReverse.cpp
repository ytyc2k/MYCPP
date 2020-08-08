#include <iostream>
using namespace std;
int main()
{
    string ss = "1234567890";
    for (int i = ss.length()-1; i >= 0; i--)
    {
        cout << ss[i];
    }
}