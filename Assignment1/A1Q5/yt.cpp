#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
string GameStr = "745683*21";char JG[5][5];
void AddBorder()
{
    srand(time(NULL));random_shuffle(GameStr.begin(), GameStr.end());
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            (i>0 && i<4) && (j>0 && j<4) ? JG[i][j]=GameStr[(i-1)*3+(j-1)%3] : JG[i][j]='0';
}
void PrintBoard()
{
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
            cout << JG[i][j] << " ";
        cout << endl;
    }
    cout << "------------------" << endl;
}

int main()
{
    AddBorder();PrintBoard();
    char num='6';
    for(int i=1; i<4; i++)
        for(int j=1; j<4; j++)
            if(JG[i][j] == num)
            {
                if(JG[i-1][j]=='*')      {JG[i-1][j]=num;JG[i][j]='*';}
                else if(JG[i+1][j]=='*') {JG[i+1][j]=num;JG[i][j]='*';}
                else if(JG[i][j+1]=='*') {JG[i][j+1]=num;JG[i][j]='*';}
                else if(JG[i][j-1]=='*') {JG[i][j-1]=num;JG[i][j]='*';}
                goto endloop;
            }
    endloop:
    PrintBoard();
}
