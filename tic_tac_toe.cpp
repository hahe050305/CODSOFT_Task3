#include<iostream>
#include <cstdlib>
#include <ctime>		// Library that acts as a seed for Random number Generation

using namespace std;

void Board_display(char *spaces);
void player_Move(char *spaces, char player);
void computer_Move(char *spaces, char computer);
bool check_Winner(char *spaces, char player, char computer);
bool check_Tie(char *spaces);

int main()
{
	cout << " \t\t\t\t\t ##### CODSOFT INTERNSHIP ##### \n" ;
	
	cout << " \n XOXO || TIC-TAC-TOE Game Project || OXOX  \n";
		
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';			// User
    char computer = 'O';		// Computer (moves done based on Random Function)
    bool running = true;

    Board_display(spaces);

    while(running)
	{
        player_Move(spaces, player);
        Board_display(spaces);
        if(check_Winner(spaces, player, computer))
		{
            running = false;
            break;
        }
        else if(check_Tie(spaces))
		{
            running = false;
            break;
        }

        computer_Move(spaces, computer);
        Board_display(spaces);
        
        if(check_Winner(spaces, player, computer))
		{
            running = false;
            break;
        }
        
        else if(check_Tie(spaces))
		{
            running = false;
            break;
        }
    }
    
    cout << "Thanks for playing!\n";
    return 0;
}

void Board_display(char *spaces)
{
	cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void player_Move(char *spaces, char player)
{
    int number;
    do
	{
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if(spaces[number] == ' ')
		{
			cout << "\n YOUR MOVE";
           spaces[number] = player;
           break; 
        }
    }
	while(!number > 0 || !number < 8);
}

void computer_Move(char *spaces, char computer)
{
    int number;
    srand(time(NULL));

    while(true)
	{
        number = rand() % 9;			// Makes  a move within 1-9 empty spaces
        if(spaces[number] == ' ')
		{
			cout << "\n COMPUTER MOVE" ;
            spaces[number] = computer;
            break;
        }
    }
}

bool check_Winner(char *spaces, char player, char computer)
{

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
	{
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
	{
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
	{
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
	{
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
	{
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
	{
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
	{
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
	{
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    
    else
	{
        return false;
    }
    return true;
}

bool check_Tie(char *spaces)
{

    for(int i = 0; i < 9; i++)
	{
        if(spaces[i] == ' ')
		{
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

