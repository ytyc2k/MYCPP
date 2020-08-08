#include <vector>
#include <iostream>
#include <algorithm>
#include<cmath>
#include <iomanip>
using namespace std;
vector<double> tme,dis;
double N,d,t,s=0,a;
int main()
{
    cout.setf(ios::fixed);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> t;
        tme.push_back(t);
        cin >> d;
        dis.push_back(d);
    }
    for(int j=0;j<N-1;j++)
    {
        a = abs((dis[j+1]-dis[j])/(tme[j+1]-tme[j]));
        if(a>s)
        {
            s=a;
        }
    }
    cout <<setprecision(1) << s;
}