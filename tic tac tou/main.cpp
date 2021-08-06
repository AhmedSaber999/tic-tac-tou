#include <iostream>
#include<windows.h>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
bool diagonals ;
//color Function :
void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}
//Shape of the first page of the game :
void Screen_Shown(string player1,string player2)
{
    SetColor(10) ;
    cout << "\n           Let's Play Tic Tac Toe \n\n";
    SetColor(15) ;
    cout << "           "<<player1<<"  -> (X)  ,  "<<player2<<" -> (O)" << endl << endl;
    cout << endl;
    SetColor(8) ;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
void Screen_Shown ()
{
    SetColor(13) ;
    cout << endl;
    SetColor(15) ;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
void Tic_Tac_Game_players(string &player1,string &player2)
{
    cout<<"           Name of the first player is : ";
    cin>>player1 ;
    cout<<"           Name of the second player is : ";
    cin>>player2;
    SetColor(14) ;
    cout<<"\n\n           Welcome "<<player1<<" And " <<player2<<" (: " <<endl ;
}
void First_Page()
{
    string s ;
    SetColor(10) ;
    cout<<"\n\n\n\n\n"<<"           "<<"[1] Start"<<"\n"<<"           "<<"[2] End"<<endl ;
    int num ;
    SetColor(15) ;
    cout<<"           " ;
    cin>>num ;
    if(num==1)
    {
        cout<<"           Diagonals Or not ??Y/N " ;
        cin>>s ;
        if(s=="Y"||s=="y")
            diagonals=true ;
        else
            diagonals=false ;

        return ;
    }
    else
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  END ,,,,THANKS (:  "<<endl ;
}

bool check_Who_the_winner ()
{
    if(square[1]==square[2] && square[2]==square[3])
        return true ;
    else if(square[4]==square[5] && square[5]==square[6])
        return true ;
    else if(square[7]==square[8] && square[8]==square[9])
        return true ;
    else if(square[1]==square[4] && square[4]==square[7])
        return true ;
    else if(square[2]==square[5] && square[5]==square[8])
        return true ;
    else if(square[3]==square[6] && square[6]==square[9])
        return true ;
    else if(diagonals==true)
    {
        if(square[1]==square[5] && square[5]==square[9])
            return true ;
        else if(square[7]==square[5] && square[5]==square[3])
            return true ;
        else
            return false ;
    }
    else
        return false ;
}
int  play_game()
{
    int player=1 ;
    char ch, number ;
    do
    {
        if(player%2==1)
            ch='X' ;
        else
            ch='O' ;
        SetColor(12) ;
        cout<<"  The number of square you want to put on !? " ;
        while(cin>>number)
        {
            if(number >='0' && number <='9')
            {
                if(square[(number - '0')]!='X' &&square[(number - '0')]!='O')
                {
                    square[(number - '0')]=ch ;
                    player++ ;
                    break ;
                }
                else
                {
                    SetColor(1) ;
                    cout<<"  Please enter valid square position "<<endl ;
                }
            }
            else
            {
                SetColor(1) ;
                cout<<"  Please enter Number of square"<<endl ;
            }
        }
        Screen_Shown() ;
        bool gameResult=check_Who_the_winner () ;
        if(gameResult==true)
            return player ;
        if(player==9)
            return 0 ;
    }
    while(player!=10 || check_Who_the_winner==false);

}

int main()
{
    string player1,player2 ;
    int Winner ;
    First_Page() ;
    Tic_Tac_Game_players (player1,player2) ;
    Screen_Shown(player1,player2) ;
    Winner=play_game() ;
    if(Winner==0)
    {
        SetColor(15) ;
        cout<<"\t\t\t\t\t GAME OVER\t\t\t\t"<<endl  ;
    }
    else
    {
        SetColor(15) ;
        Winner-- ;
        Winner=Winner%2 ;
        if(Winner==1)
            cout<<"The Winner is  : "<<player1<<endl  ;
        else
            cout<<"The Winner is  : "<<player2<<endl  ;
    }

    return 0 ;
}
