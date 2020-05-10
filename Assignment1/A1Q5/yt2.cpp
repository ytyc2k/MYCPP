#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
string GameStr = "1237*6548";char JG[5][5];
void AddBorder()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            JG[i][j]=(i%4!=0 || j%4!=0) ? GameStr[(i-1)*3+(j-1)%3] : '0';
}
void PrintBoard()
{
    for(int i=0; i<9; i++)
    {
        cout << GameStr[i] << " ";
        if ((i+1)%3==0) cout << endl;
    }
    cout << "------------------" << endl;
}

int main()
{
    char num='9';
    //srand(time(NULL));random_shuffle(GameStr.begin(), GameStr.end());
    AddBorder();
    while(num!='q')
    {
        PrintBoard();

        cout << "Type the number beside the asterisk to switch it with the asterisk: ";
        cin >> num;
        int x=GameStr.find(num);
        int i=x/3+1;int j=x%3+1;
        if(JG[i-1][j]=='*')      {JG[i-1][j]=num;JG[i][j]='*';GameStr[(i-2)*3+(j-1)%3]=num;GameStr[x]='*';}
        else if(JG[i+1][j]=='*') {JG[i+1][j]=num;JG[i][j]='*';GameStr[i*3+(j-1)%3]=num;GameStr[x]='*';}
        else if(JG[i][j+1]=='*') {JG[i][j+1]=num;JG[i][j]='*';GameStr[(i-1)*3+j%3]=num;GameStr[x]='*';}
        else if(JG[i][j-1]=='*') {JG[i][j-1]=num;JG[i][j]='*';GameStr[(i-1)*3+(j-2)%3]=num;GameStr[x]='*';}
        if(GameStr=="12345678*"){cout << "YOU WON!!!";break;}
    }
}
