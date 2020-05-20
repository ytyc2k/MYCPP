#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int Row,Column;
int Mine = 0;
string TempMap;
vector <string> MineMap;
vector <int> Rows,Columns;
int Minesweeper(int r, int c)
{
    int Area = 0;
    if(r>=0 && r<16 && c>=0 && c<30 && MineMap[r][c] == '.')
    {
        Area=1;
        MineMap[r][c]='A';
        Area +=Minesweeper(r + 1, c);
        Area +=Minesweeper(r - 1, c);
        Area +=Minesweeper(r, c - 1);
        Area +=Minesweeper(r, c + 1);
        Area +=Minesweeper(r + 1, c + 1);
        Area +=Minesweeper(r - 1, c + 1);
        Area +=Minesweeper(r + 1, c - 1);
        Area +=Minesweeper(r - 1, c - 1);
    }
    else if(r>=0 && r<16 && c>=0 && c<30 && MineMap[r][c] = '')
    {
        Area = 1;
        MineMap[r][c]='B';
    }
    return Area;
}
int main()
{
    ifstream InFile("Minesweeper.txt",ios::in);//open the house plan file
    if(!InFile.is_open())//if can't open the file then send an error
    {
        cout << "Error: opening file fail" << endl;
        exit(0);
    }
    for(int i=0; i<16; i++)
    {
        InFile >> TempMap;
        MineMap.push_back(TempMap);

    }
    while(!InFile.eof())
    {
        InFile >> Row >> Column;
        Rows.push_back(Row-1);
        Columns.push_back(Column-1);
    }
    InFile.close();
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<30; j++)
        {
            if(MineMap[i][j]!='X' && i-1>=0 && j-1>=0 && i+1<=15 && j+1<=29)
            {
                if(MineMap[i-1][j-1]=='X'||MineMap[i-1][j]=='X'||MineMap[i-1][j+1]=='X'||MineMap[i][j-1]=='X'||MineMap[i][j+1]=='X'||MineMap[i+1][j-1]=='X'||MineMap[i+1][j]=='X'||MineMap[i+1][j+1]=='X')
                    MineMap[i][j]='?';
            }
            else if(MineMap[i][j]!='X' && i==0 && j-1>=0 && i+1<=15 && j+1<=29)
            {
                if(MineMap[i][j-1]=='X'||MineMap[i][j+1]=='X'||MineMap[i+1][j-1]=='X'||MineMap[i+1][j]=='X'||MineMap[i+1][j+1]=='X')
                    MineMap[i][j]='?';
            }
            else if(MineMap[i][j]!='X' && i-1>=0 && j==0 && i+1<=15 && j+1<=29)
            {
                if(MineMap[i-1][j]=='X'||MineMap[i-1][j+1]=='X'||MineMap[i][j+1]=='X'||MineMap[i+1][j]=='X'||MineMap[i+1][j+1]=='X')
                    MineMap[i][j]='?';
            }
            else if(MineMap[i][j]!='X' && i-1>=0 && j-1>=0 && i==15 && j+1<=29)
            {
                if(MineMap[i-1][j-1]=='X'||MineMap[i-1][j]=='X'||MineMap[i-1][j+1]=='X'||MineMap[i][j-1]=='X'||MineMap[i][j+1]=='X')
                    MineMap[i][j]='?';
            }
            else if(MineMap[i][j]!='X' && i-1>=0 && j-1>=0 && i+1<=15 && j==29)
            {
                if(MineMap[i-1][j-1]=='X'||MineMap[i-1][j]=='X'||MineMap[i][j-1]=='X'||MineMap[i+1][j-1]=='X'||MineMap[i+1][j]=='X')
                    MineMap[i][j]='?';
            }
        }
    }
    for(int i=0; i<Rows.size(); i++)
    {
        if(MineMap[Rows[i]][Columns[i]]=='X')
        {
            cout << "MINE at (" << Rows[i]+1 << "," << Columns[i]+1 << ") - YOU LOSE" << endl;
        }
        else if(MineMap[Rows[i]][Columns[i]]=='?')
        {
            if(MineMap[Rows[i]-1][Columns[i]]=='X') Mine++;
            if(MineMap[Rows[i]-1][Columns[i]-1]=='X') Mine++;
            if(MineMap[Rows[i]-1][Columns[i]+1]=='X') Mine++;
            if(MineMap[Rows[i]][Columns[i]+1]=='X') Mine++;
            if(MineMap[Rows[i]+1][Columns[i]]=='X') Mine++;
            if(MineMap[Rows[i]][Columns[i]-1]=='X') Mine++;
            if(MineMap[Rows[i]+1][Columns[i]+1]=='X') Mine++;
            if(MineMap[Rows[i]+1][Columns[i]-1]=='X') Mine++;
            cout << "NO MINE at (" << Rows[i]+1 << "," << Columns[i]+1 << ") - "<< Mine <<" SURROUNDING IT" << endl;
            Mine=0;
        }
        else
        {
            cout << "NO MINE at (" << Rows[i]+1 << "," << Columns[i]+1 << ") - "<< Minesweeper(Rows[i],Columns[i]) <<" SQUARES REVEALED" << endl;
        }
    }
    for(int i=0; i<MineMap.size(); i++)
    {
        cout << MineMap[i]<<endl;
    }
}
