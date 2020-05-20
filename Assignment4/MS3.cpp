#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> MineMap;
struct point
{
    int x, y;
};
vector<point> samples;

int R = 16;
int C = 30;

void ReadFile(){
    ifstream InFile("Minesweeper.txt", ios::in); //open the house plan file
    if (!InFile.is_open())                       //if can't open the file then send an error
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    string TempMap;
    MineMap.push_back(string(C+2, 'I'));
    for (int i = 0; i < R; i++)
    {
        InFile >> TempMap;
        MineMap.push_back('I' + TempMap + 'I');
    }
    MineMap.push_back(string(C+2, 'I'));
    while (!InFile.eof())
    {
        point temp;
        InFile >> temp.x >> temp.y;
        samples.push_back(temp);
    }
    InFile.close();
}
int Minesweeper(int r, int c)
{
    int Area = 0;
    if (r > 0 && r < R + 1 && c > 0 && c < C + 1)
    {

        if (MineMap[r][c] == '.')
        {
            Area = 1;
            MineMap[r][c] = '-';
            Area += Minesweeper(r + 1, c);
            Area += Minesweeper(r - 1, c);
            Area += Minesweeper(r, c - 1);
            Area += Minesweeper(r, c + 1);
            Area += Minesweeper(r + 1, c + 1);
            Area += Minesweeper(r - 1, c + 1);
            Area += Minesweeper(r + 1, c - 1);
            Area += Minesweeper(r - 1, c - 1);
        }
        else if (MineMap[r][c] != '-')
        {
            Area = 1;
            MineMap[r][c] = '-';
        }
    }
    return Area;
}
void FlagMinesNum(){
    for (int x = 1; x <= R; x++)
    {
        for (int y = 1; y <= C; y++)
        {
            int k = 0;
            if (MineMap[x][y] == '.')
            {
                if (MineMap[x][y - 1] == 'X') MineMap[x][y] = char(k++ + 49);
                if (MineMap[x][y + 1] == 'X') MineMap[x][y] = char(k++ + 49);
                if (MineMap[x + 1][y] == 'X') MineMap[x][y] = char(k++ + 49);
                if (MineMap[x - 1][y] == 'X') MineMap[x][y] = char(k++ + 49);
                if (MineMap[x - 1][y - 1] == 'X')  MineMap[x][y] = char(k++ + 49);
                if (MineMap[x - 1][y + 1] == 'X')  MineMap[x][y] = char(k++ + 49);
                if (MineMap[x + 1][y - 1] == 'X')  MineMap[x][y] = char(k++ + 49);
                if (MineMap[x + 1][y + 1] == 'X')  MineMap[x][y] = char(k++ + 49);
            }
        }
    }
}
void DisplayMap()
{
    for (string ss : MineMap)
    {
        cout << ss << endl;
    }
    for (point p : samples)
    {
        cout << p.x << ',' << p.y << endl;
    }
}
void DisplayResults(){
    for (int i=0;i<samples.size();i++)
    {
        int x=samples[i].x;int y=samples[i].y;
        if (MineMap[x][y] == 'X')
            cout << "MINE at (" << x << "," << y << ") - YOU LOSE" << endl;
        else if (MineMap[x][y] != '.')
            cout << "NO MINE at (" << x << "," << y << ") - " << MineMap[x][y] << " SURROUNDING IT" << endl;
        else
        {
            vector<string> TempMineMap = MineMap;
            cout << "NO MINE at (" << x << "," << y << ") - " << Minesweeper(x, y) << " SQUARES REVEALED" << endl;
            MineMap = TempMineMap;
        }
    }
}

int main()
{
    ReadFile();
    FlagMinesNum();
    DisplayMap();
    DisplayResults();
}