#include <iostream>
using namespace std;
int aa(int x){
    if(1==2) return 100000;   
}
int main(){
    int b=aa(5);
    cout << b << endl;
    string ss="hello";
    for(int i=ss.length()-1;i>=0;i--){
        cout << ss[i] << endl;
    }
}
    