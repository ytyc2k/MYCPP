/*
Jun Yang
2020-5-6
The project can accept a house plan file with tile number and the size of house
Then it will show how many rooms will have the tiling installed and how many tiles left
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int Squares,Row,Column;//initialize the variables and vectors
string TempPlan;
vector <string> HousePlan;
vector <int> rooms;
int countRoom(int r, int c)//create a recursive function to count each room's size
{
    int area = 0;
    if(r>=0 && r<Row && c>=0 && c<Column && HousePlan[r][c] == '.')//if the area is in range then replace it and check next one
    {
        area = 1;
        HousePlan[r][c]='A';
        area +=countRoom(r + 1, c);//check below
        area +=countRoom(r - 1, c);//check above
        area +=countRoom(r, c - 1);//check left
        area +=countRoom(r, c + 1);//check right
    }
    return area;
}
int main()
{
    ifstream InFile("HousePlan.txt",ios::in);//open the house plan file
    if(!InFile.is_open())//if can't open the file then send an error
    {
        cout << "Error: opening file fail" << endl;
        exit(0);
    }
    InFile >> Squares >> Row >> Column;//input squares, row and column number
    while(!InFile.eof())//if the pointer is not at the end of the file, then input the data
    {
        InFile >> TempPlan;
        HousePlan.push_back(TempPlan);

    }
    InFile.close();//close the file
    for(int i=0; i<Row; i++)//put all room's area information into the vector line by line
    {
        for(int j=0; j<Column; j++)
        {
            int RoomArea=countRoom(i,j);//calculate each room's area
            if(RoomArea)//if area greater than 0 then record it
                rooms.push_back(RoomArea);
        }
    }
    sort(rooms.rbegin(),rooms.rend());//arrange the area of rooms from the biggest to the smallest
    int roomNum=0;
    for(; roomNum<rooms.size(); roomNum++)//compare the squares to the area of rooms
    {
        if(Squares>=rooms[roomNum])//if there're enough tiles then add 1 installed room, and minus the area of the room
        {
            Squares = Squares - rooms[roomNum];
        }
        else//else stop installing
            break;
    }
    cout << roomNum << " rooms, " << Squares <<" square metre(s) left over";//print how many rooms are installed and how many tiles left
}
