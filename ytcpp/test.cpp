#include <iostream>
using namespace std;
int main()
{
    // char const *ss="1234567890";
    // int i=0;
    // while (ss[++i]);
    // while(ss[i-1]) 
    //     cout << ss[--i];
    
    int arr[]={2,3,4,8,5,3,4,1,0,7};
    int ln = 10;
    cout << ln;
    for (int i = 0; i < ln - 1; i++) {
        for (int j = 0; j < ln - 1 - i; j++) {
            if (arr[j] > arr[j+1]) 
            {        
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < ln - 1; i++) 
    {
        cout << arr[i] << endl;
    }
}