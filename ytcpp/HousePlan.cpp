#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int Tiles, Row, Col;
vector<string> HousePlan;
vector<int> Rooms;

void ReadFile()
{
    ifstream InFile("HousePlan.txt", ios::in); //open the house plan file
    if (!InFile.is_open())                     //if can't open the file then send an error
    {
        cout << "Error: opening file fail" << endl;
        exit(0);
    }
    InFile >> Tiles >> Row >> Col; //input squares, row and column number
    string TempLine;
    while (!InFile.eof()) //if the pointer is not at the end of the file, then input the data
    {
        InFile >> TempLine;
        HousePlan.push_back(TempLine);
    }
    InFile.close(); //close the file
}
int countRoom(int r, int c)
{
    if (r >= 0 && r < Row && c >= 0 && c < Col && HousePlan[r][c] == '.')
    {
        int area = 1;
        HousePlan[r][c] = 'A';
        area += countRoom(r + 1, c); // check below
        area += countRoom(r - 1, c); // check above
        area += countRoom(r, c - 1); // check left
        area += countRoom(r, c + 1); // check right
        return area;
    } else return 0;
}

int main()
{
    ReadFile();
    for (int i = 0; i < Row; i++)
        for (int j = 0; j < Col; j++)
        {
            int k = countRoom(i, j);
            if (k) Rooms.push_back(k);
        }
    sort(Rooms.rbegin(), Rooms.rend());
    int N = 0;
    for (; N < Rooms.size(); N++)
        if (Tiles >= Rooms[N]) Tiles -= Rooms[N]; else break;
    cout << N << " Rooms, " << Tiles << " square metre(s) left over" << endl;
}