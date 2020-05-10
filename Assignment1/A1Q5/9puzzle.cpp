//Jun Yang 2020-2-25
/*
This is a board game which you can only use valid swaps between the asterisk (*) and neighbouring numbers.
Only accept valid input (digits 1-8) and valid moves (up, down, left or right squares adjacent to the asterisk).
Invalid moves will not change the board. The game ends when you win (in order: 1 2 3 4 5 6 7 8 *) or when you lose (out of order: 1 2 3 4 5 6 8 7 *).
*/
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
string GameStr = "12345678*";//Initialize the game board with the string
char num='9';//Initialize the number to store player's input
int main()
{
    srand(time(NULL));//Shuffle the game string in a random number
    random_shuffle(GameStr.begin(), GameStr.end());
    while(1)//Make the programe keep running
    {
        for(int i=0; i<9; i++)//Print the game board
        {
            cout << GameStr[i] << " ";
            if ((i+1)%3==0)//Change the line every 3 numbers to set a 3*3 board
                cout << endl;
        }
        cout << "Type the number beside the asterisk to switch it with the asterisk: ";//Ask for the swap number beside the asterisk
        cin >> num;//Store the number as variable num
        int positionNum=GameStr.find(num);//Find the position of the number
        int positionAster=GameStr.find('*');//Find the position of the asterisk
        int x=positionNum/3;//Find the vertical ordinate of the number
        int y=positionNum%3;//Find the horizontal ordinate of the number
        int up=3*(x-1)+y;//Find the position of the number above the input number
        if (x-1<0)//If the input number is in the toppest line, then set the up position out of the range
            up=99;
        int dn=3*(x+1)+y;//Find the position of the number under the input number
        if (x+1>2)//If the input number is in the lowest line, then set the down position out of the range
            dn=99;
        int lf=3*x+y-1;//Find the position of the number at the left of the input number
        if (y-1<0)//If the input number is in the most left line, then set the left position out of the range
            lf=99;
        int rt=3*x+y+1;//Find the position of the number at the right of the input number
        if (y+1>2)//If the input number is in the most right line, then set the right position out of the range
            rt=99;
        if(positionAster==up||positionAster==dn||positionAster==lf||positionAster==rt)//If the asterisk's position is the same as one of the four positions beside the input number
        {
            GameStr[positionAster]=num;//Swap the asterisk with the input number
            GameStr[positionNum]='*';
        }
        if(GameStr=="12345678*")//If the game string is in the order of "12345678*", then player wins, stop the program
        {
            cout << "YOU WIN!!!";
            break;
        }
        else if(GameStr[8]=='*')//If the game string is out of the order, then player loses, stop the program
        {
            cout << "YOU LOSE!!!";
            break;
        }
    }
}
