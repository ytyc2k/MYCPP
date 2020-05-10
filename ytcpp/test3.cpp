#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int Row=14;
int Col=16;
vector <string> aa={
    "IIIIIIIIIIIIIIII",
    "I......I.......I",
    "I......III.....I",
    "I........I.....I",
    "I........IIIIIII",
    "IIIIIIIIII.....I",
    "I.I......I.....I",
    "III..III.I.....I",
    "I....I.IIIII...I",
    "I....I.....III.I",
    "I....I.......I.I",
    "I....I.....III.I",
    "I....I.....I...I",
    "IIIIIIIIIIIIIIII"
    };
vector <int> rooms;
int countRoom(int r, int c){
    int area = 1;
    if(r>=0 && r<Row && c>=0 && c<Col && aa[r][c] == '.'){
        aa[r][c]='A';
        area +=countRoom(r + 1, c); // check below
        area +=countRoom(r - 1, c); // check above
        area +=countRoom(r, c - 1); // check left
        area +=countRoom(r, c + 1); // check right
        return area;
    }
    else
    {
        return 0;
    }   
}

int main(){
    //cout << countRoom(0,1)<< endl;
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            int k=countRoom(i,j);
            if(k>0){
                rooms.push_back(k);
            }
        }
    }
    
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            cout << aa[i][j];
        }
        cout << endl;
    }

    sort(rooms.rbegin(),rooms.rend());
    for(int x:rooms){
        cout << x << ',' <<endl;
    }
    cout << rooms.size() << endl;
}