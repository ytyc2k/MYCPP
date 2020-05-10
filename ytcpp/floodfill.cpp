#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int UnUsedTiles = 125;
int Row = 14;
int Col = 16;
vector<string> tile = {
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
    "IIIIIIIIIIIIIIII"};
vector<int> Rooms;
int countRoom(int r, int c)
{
    if (r >= 0 && r < Row && c >= 0 && c < Col && tile[r][c] == '.')
    {
        int area = 1;
        tile[r][c] = 'A';
        area += countRoom(r + 1, c); // check below
        area += countRoom(r - 1, c); // check above
        area += countRoom(r, c - 1); // check left
        area += countRoom(r, c + 1); // check right
        return area;
    }
    else return 0;
}
int main()
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            int k = countRoom(i, j);
            if (k) Rooms.push_back(k);
        }
    }
    sort(Rooms.rbegin(), Rooms.rend());
    int N = 0;
    for (; N < Rooms.size(); N++)
    {
        if (UnUsedTiles >= Rooms[N]) UnUsedTiles -= Rooms[N]; 
        else break;
    }
    cout << N << " rooms, " << UnUsedTiles << " square metre(s) left over" << endl;
}