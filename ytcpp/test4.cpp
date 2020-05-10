#include <iostream>
using namespace std;
int fn(int x)
{
    1==1? x=100:x=200;
    return x;
}
int main(){
    int b=fn(5);
    cout << b << endl;
    string a="123456";
    for(int x=a.length()-1;x>=0;x--){
        cout << a[x];
    }
}
