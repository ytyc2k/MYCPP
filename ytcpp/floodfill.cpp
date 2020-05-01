#include <iostream>
using namespace std;
int tiles=13;int R=2;int C=3;
char tile[][4]={".I.",".I."};
int countRoom(int r, int c){   
    int area = 1;
    cout << "hello" << endl;
    if(r>=0 && r<R && c>=0 && c<C && tile[r][c]=='.'){
        tile[r][c]='A';
        cout << "line " << r << ' '<< c << " area " << area << endl;
        area +=countRoom(r + 1, c); // check below
        area +=countRoom(r - 1, c); // check above
        area +=countRoom(r, c - 1); // check left
        area +=countRoom(r, c + 1); // check right
        return area;
    }
    else 
        return 0;  
}
int main(){
    cout << countRoom(0,0) << endl;
    for (int i=0; i<R; i++) 
    { 
        for (int j=0; j<C; j++) 
            cout << tile[i][j] << " "; 
            cout << endl; 
    } 
} 