#include <iostream>
#include <vector>
using namespace std;
int UnUsedTiles = 125;
int Row = 14;
int Col = 16;
char tile[][17] = {
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
vector<int> TilesAcount;
int countRoom(int r, int c)
{
    int area = 1;
    if (r >= 0 && r < Row && c >= 0 && c < Col && tile[r][c] == '.')
    {
        tile[r][c] = 'A';
        area += countRoom(r + 1, c); // check below
        area += countRoom(r - 1, c); // check above
        area += countRoom(r, c - 1); // check left
        area += countRoom(r, c + 1); // check right
        return area;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int k = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            k = countRoom(i, j);
            if (k != 0)
                TilesAcount.push_back(k);
        }
    }
    cout << "Room's acount is: " << TilesAcount.size() << endl;
    int UsedTiles = 0;
    for (int i = 0; i < TilesAcount.size(); i++)
    {
        UsedTiles += TilesAcount[i];
        cout << "Room" << i << " has " << TilesAcount[i] << " tiles. " << endl;
    }
    cout << "Total Used Tiles are: " << UsedTiles << ". Left Tiles are: " << UnUsedTiles - UsedTiles << endl;
}