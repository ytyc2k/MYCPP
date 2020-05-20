#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <string> MineMap;
struct coordinate
{
    int x;
    int y;
};
vector <coordinate> ps;
int row=16;
int col=30;
void RedFile(){
    string tempstr;
    ifstream InFile("Minesweeper.txt", ios::in); //open the house plan file
    if (!InFile.is_open())                       //if can't open the file then send an error
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    for (int i = 0; i < 16; i++)
    {
        InFile >> tempstr;
            MineMap.push_back(tempstr);
    }
    while (!InFile.eof())
    {
        coordinate temp;
        InFile >> temp.x >> temp.y;
        ps.push_back(temp);
    }
    InFile.close();
}
int Minesweeper(int x, int y)
{
    int Area = 0;
    if (x > 0 && x < row && y > 0 && y < col && MineMap[x][y] == '.')
    {
        Area = 1;
        MineMap[x][y] = 'A';
        Area += Minesweeper(x + 1, y);
        Area += Minesweeper(x - 1, y);
        Area += Minesweeper(x, y - 1);
        Area += Minesweeper(x, y + 1);
        Area += Minesweeper(x + 1, y + 1);
        Area += Minesweeper(x - 1, y + 1);
        Area += Minesweeper(x + 1, y - 1);
        Area += Minesweeper(x - 1, y - 1);
    }
    else if (x > 0 && x < row && x > 0 && x < col && MineMap[x][y] == '?')
    {
        Area = 1;
        MineMap[x][y] = 'B';
    }
    return Area;
}
void Display(){
    for (string ss:MineMap){
        cout << ss << endl;
    }
    for (coordinate p:ps){
        cout << p.x << ',' << p.y << endl;
    }
}
int main()
{
    RedFile();

    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
        {
            int ot=0;
            int k=MineMap[x][y];
            if (k=='X') continue;
            if (k=='.') 
            {
                if (y-1<0) 
                {
                    if (MineMap[x][y]=='X') k='?';
                }
                
            }
            // if (MineMap[x][y - 1] == 'X'&& MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x][y + 1] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x + 1][y] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x - 1][y] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x - 1][y - 1] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x - 1][y + 1] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x + 1][y - 1] == 'X'&&MineMap[x][y]=='.')
            //     MineMap[x][y] = '?';
            // if (MineMap[x + 1][y + 1] == 'X'&&MineMap[x][y]=='.')
                
        }
    } 

    Display();
    // for(int i=0; i<samples.size(); i++)
    // {
    //     if(MineMap[samples[i].x][samples[i].y]=='X')
    //         cout << "MINE at (" << samples[i].x << "," << samples[i].y << ") - YOU LOSE" << endl;
    //     else if(MineMap[samples[i].x][samples[i].y]=='?')
    //     {
    //         if(MineMap[samples[i].x-1][samples[i].y]=='X') Mine++;
    //         if(MineMap[samples[i].x-1][samples[i].y-1]=='X') Mine++;
    //         if(MineMap[samples[i].x-1][samples[i].y+1]=='X') Mine++;
    //         if(MineMap[samples[i].x][samples[i].y+1]=='X') Mine++;
    //         if(MineMap[samples[i].x+1][samples[i].y]=='X') Mine++;
    //         if(MineMap[samples[i].x][samples[i].y-1]=='X') Mine++;
    //         if(MineMap[samples[i].x+1][samples[i].y+1]=='X') Mine++;
    //         if(MineMap[samples[i].x+1][samples[i].y-1]=='X') Mine++;
    //         cout << "NO MINE at (" << samples[i].x << "," << samples[i].y << ") - "<< Mine <<" SURROUNDING IT" << endl;
    //         Mine=0;
    //     }
    //     else
    //         cout << "NO MINE at (" << samples[i].x << "," << samples[i].y << ") - "<< Minesweeper(samples[i].x,samples[i].y) <<" SQUARES REVEALED" << endl;
    // }
}