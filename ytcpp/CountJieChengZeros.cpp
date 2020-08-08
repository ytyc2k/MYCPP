#include <iostream>
using namespace std;
long int JC(int N)
{
    if (N==1) return 1;
    else return N*JC(N-1);
}
int main()
{
    int N=102;
    cout << JC(N) << endl;
    int count = 0;
    while (N > 0)
    {
        count+=N/5;
        N/=5;
    }
    cout << count <<endl;
}