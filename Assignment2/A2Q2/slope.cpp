/*
Jun Yang
2020-4-13
This project The project will ask for points number n and the x and y coordinates of those points.
Then it will calculate the slope between any two of the points that the user specifies.
This selection will keep repeating until zero is entered.
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<double> xVal,yVal;//Create two vectors to save the x value and y value
    int PointNum;//Ask input for the number of points
    cout << "How many points? ";
    cin >> PointNum;
    int x,y;
    for(int i=1; i<=PointNum; i++)//Save all points' coordinates into vectors
    {
        cout << "Input point #" << i << endl;//Ask for the coordinates
        cin >> x;
        cin >> y;
        xVal.push_back(x);//Save x coordinates into vectors
        yVal.push_back(y);//Save y coordinates into vectors
    }
    int point1,point2;//Create the variables for two points, in order to create the slope between them
    while(1)//Keep repeating this process
    {
        cout << "Select two points: "<<endl;//Ask for 2 points and record them
        cin >> point1;
        if(point1==0)//If the input is 0, stop immediately
        {
            cout << "BYE!";
            break;
        }
        else
        {
            cin >> point2;
            if(point2==0)
            {
                cout << "BYE!";
                break;
            }
            double slope = (yVal[point1-1]-yVal[point2-1])/(xVal[point1-1]-xVal[point2-1]);//Calculate the slope of the segement by using formula y1-y2/x1-x2
            cout << "The slope of the line segment from (" <<xVal[point1-1]<<","<<yVal[point1-1]<<") to ("<<xVal[point2-1]<<","<<yVal[point2-1]<<") is " <<slope << endl;//Print the final answer
        }
    }
}
