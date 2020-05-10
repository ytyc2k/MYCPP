//Jun Yang 2020-2-20
//This program allows two words to cross at the common letter.You need to input two words and the programe would rint the two words crossingon the common letter in crossword fashion.
//The program would stop execution when one of the word you input is "q".
#include <iostream>
using namespace std;
int main()
{
    string HoriStr;//Set the across string
    string VertStr;//Set the down string
    int HoriNum;//The number of the across string where it overlaps
    int VertNum;//The number of the down string where it overlaps
    while(1)//Make the programe keep running
    {
        cout << "Across word? ";//Input a across word
        cin >> HoriStr;
        cout << "Down word? ";//Input a down word
        cin >> VertStr;
        for(int i=0; i<HoriStr.length(); i++)//Check the across word if it has the same letter with the down word
        {
            if(VertStr.find(HoriStr[i])!=-1)//Check if there's any same letter in two strings
            {
                HoriNum = i;//Record the number of the overlap of two strings in horizontal string
                VertNum = VertStr.find(HoriStr[i]);//Record the number of the overlap of two strings in vertical string
                break;//Break the loop to fix the number
            }
        }
        for(int k=0; k<VertStr.length(); k++)//Check every letter in the down word
        {
            if(k==VertNum)//If the letter overlaps with the across word, then print it
                cout << HoriStr << endl;
            for(int l=0; l<HoriNum; l++)
            {
                if(k!=VertNum)//If not, leave space for the across word
                    cout << " ";
            }
            if(k!=VertNum)//Then print the vertical letter
                cout << VertStr[k] << endl;
        }
        if(HoriStr.find('q')!=-1||VertStr.find('q')!=-1)
            break;//If there's Q, jump out of the loop
    }
}
