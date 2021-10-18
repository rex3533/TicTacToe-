#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string playagain;
void board(char TTTBoard[]);
void playermove(char TTTBoard[]);
void robotmove(char TTTBoard[]);
int checkwin(char TTTBoard[]);
int win;
int player = 1;
int main()
{
	do {
		char TTTBoard[9] = {'1','2','3','4','5','6','7','8','9'};
        do {
            board(TTTBoard);
            playermove(TTTBoard);
            player++;
            board(TTTBoard);
            checkwin(TTTBoard);
            robotmove(TTTBoard);
           checkwin(TTTBoard);
           
        } while (win == 2);
        board(TTTBoard);
        checkwin(TTTBoard);
        if (win == 1)
        {
            cout << "Player "<< player << " wins\n ";
            cout << "do you want to play again?\n";
            cin >> playagain;

        }
        else if (checkwin == 0)
        {
            cout << "Game draw";
            cout << "do you want to play again?\n";
            cin >> playagain;
        }
	} while (playagain == "yes" or playagain == "YES");

	return 0;
}

void board(char TTTBoard[])
{
    system("cls");
    cout << "       Tic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << TTTBoard[0] << "  |  " << TTTBoard[1] << "  |  " << TTTBoard[2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << TTTBoard[3] << "  |  " << TTTBoard[4] << "  |  " << TTTBoard[5] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << TTTBoard[6] << "  |  " << TTTBoard[7] << "  |  " << TTTBoard[8] << endl;
    cout << "\t\t     |     |     " << endl << endl;
}
void playermove(char TTTBoard[])
{
    
    int player = 1;
    cout << "player "<< player << ", pick a number between 1 and 9.\n";
    int playeranswer = 0;
    bool willloop = true;
    int robotanswer = 0;
    srand(static_cast <unsigned int>(time(0)));
    //if (player == 1) left this here just in case
    {
        do {
            while (!(cin >> playeranswer) || playeranswer > 9 || playeranswer < 1)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid move";

            }
            if (playeranswer == 1 && TTTBoard[0] == '1')
            {
                TTTBoard[0] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 2 && TTTBoard[1] == '2')
            {
                TTTBoard[1] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 3 && TTTBoard[2] == '3')
            {
                TTTBoard[2] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 4 && TTTBoard[3] == '4')
            {
                TTTBoard[3] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 5 && TTTBoard[4] == '5')
            {
                TTTBoard[4] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 6 && TTTBoard[5] == '6')
            {
                TTTBoard[5] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 7 && TTTBoard[6] == '7')
            {
                TTTBoard[6] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 8 && TTTBoard[7] == '8')
            {
                TTTBoard[7] = 'x';
                willloop = false;
                player++;
            }
            else if (playeranswer == 9 && TTTBoard[8] == '9')
            {
                TTTBoard[8] = 'x';
                willloop = false;
                player++;
            }
            else
            {
                cout << "Invalid move \n ";
                willloop = true;
            }
        } while (willloop);
        player++;
    }
   
}
int checkwin(char TTTBoard[])
{
    
    // 1 means game end with result, 2 means game is ongoing, 0 means tie
    if (TTTBoard[0] == TTTBoard[1] && TTTBoard[1] == TTTBoard[2])
        //top row
    {
        win = 1;
        return 1;
    }
    else if (TTTBoard[3] == TTTBoard[4] && TTTBoard[4] == TTTBoard[5])
    {//middle row
        win = 1;
        return 1;
    }
    else if (TTTBoard[6] == TTTBoard[7] && TTTBoard[7] == TTTBoard[8])
    {//bottom row
        win = 1;
        return 1;
    }
    else if (TTTBoard[0] == TTTBoard[3] && TTTBoard[3] == TTTBoard[6])
    {//1st column 
        win = 1;
        return 1;
    }
    else if (TTTBoard[1] == TTTBoard[4] && TTTBoard[4] == TTTBoard[7])
    {//2nd column
        win = 1;
        return 1;
    }
    else if (TTTBoard[2] == TTTBoard[5] && TTTBoard[5] == TTTBoard[8])
    {//3th column
        win = 1;
        return 1;
    }
    else if (TTTBoard[0] == TTTBoard[4] && TTTBoard[4] == TTTBoard[8])
    {// a "\"
        win = 1;
        return 1;
    }
    else if (TTTBoard[2] == TTTBoard[4] && TTTBoard[4] == TTTBoard[6])
    {// a "/"
        win = 1;
        return 1;
    }//this is for tie
    else if (TTTBoard[0] != '1' && TTTBoard[1] != '2' && TTTBoard[2] != '3'
        && TTTBoard[3] != '4' && TTTBoard[4] != '5' && TTTBoard[5] != '6'
        && TTTBoard[6] != '7' && TTTBoard[7] != '8' && TTTBoard[8] != '9')
    {
        win = 0;
        return 0;
    
    }
    else //ongoing game
    {
        win = 2;
        return 2;
    }
    
}
void robotmove(char TTTBoard[])
{
    int player = 2;
    bool willloop = true;
    int robotanswer = 0;
    srand(static_cast <unsigned int>(time(0)));
    cout << "AI's turn\n";
    do {
        robotanswer = (rand() % 9) + 1;
       
        if (robotanswer == 1 && TTTBoard[0] == '1')
        {
            TTTBoard[0] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 2 && TTTBoard[1] == '2')
        {
            TTTBoard[1] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 3 && TTTBoard[2] == '3')
        {
            TTTBoard[2] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 4 && TTTBoard[3] == '4')
        {
            TTTBoard[3] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 5 && TTTBoard[4] == '5')
        {
            TTTBoard[4] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 6 && TTTBoard[5] == '6')
        {
            TTTBoard[5] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 7 && TTTBoard[6] == '7')
        {
            TTTBoard[6] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 8 && TTTBoard[7] == '8')
        {
            TTTBoard[7] = 'o';
            willloop = false;
            player--;
        }
        else if (robotanswer == 9 && TTTBoard[8] == '9')
        {
            TTTBoard[8] = 'o';
            willloop = false;
            player--;
        }
        else if((TTTBoard[0] != '1' && TTTBoard[1] != '2' && TTTBoard[2] != '3'
            && TTTBoard[3] != '4' && TTTBoard[4] != '5' && TTTBoard[5] != '6'
            && TTTBoard[6] != '7' && TTTBoard[7] != '8' && TTTBoard[8] != '9'))
        {
            cout << "Tie\n";
            cout << "do you want to play again?\n";
            cin >> playagain;
            break;
        }
        else
        {//this checks the board and makes sure the AI has a move
            cout << "Invalid move \n ";
            willloop = true;
        }
        
    } while (willloop);
    

}
