#ifndef GAME_H
#define GAME_H

//hello world
//
//
//?

#include <iostream>

//-FUNCTION PROTOTYPES
void DrawBoard();		// Draws the board each turn!
void GetInput(int position_number);		// Asks player for (valid) input and returns that value!
int CheckWinner();		// Checks for a winner!

//-CONSTANTS
const int FREE = 0;		// Board slot not taken
const int FALSE = 0;
const int X = 1;		// Player X
const int O = 2;		// Player Y
const int DRAW = -1;	// Game is a draw

//-GLOBAL VARS
char board[9] = { '1','2','3','4','5','6','7','8','9' };	// The board!
int player = X;			// The player!


//-FUNCTION DEFINITIONS (View Prototypes for Info)
void DrawBoard()
{

	std::cout

        << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n"
        << "-----------\n"
        << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n"
        << "-----------\n"
        << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

void GetInput(int position_input)
{

    int flag = 1;
	// Checks Input Validity //
	while (true)
    {

        if(position_input < 0){
            flag = 0;
            std::cout << "INVALID POSITION, TRY AGAIN...\n";
            break;
        }
        position_input--;			// Decrement input since arrays begin at 0
        if (position_input > 8 || board[position_input] == 'X' || board[position_input] == 'O')
		{
            flag = 0;
            std::cout << "INVALID POSITION, TRY AGAIN...\n";

            break;
		}
		break;
	}
	// Updates Board Value //

    if ((player == X) && (flag == 1)){

        board[position_input] = 'X';

    }
    else {
        board[position_input] = 'O';

    }
}

// DISCLAIMER: This function is still a spaghetti mess-- but higher quality spaghetti.
int CheckWinner()
{

	// Check Row Wins //
	if (board[0] == board[1] && board[1] == board[2]) return player;
	else if (board[3] == board[4] && board[4] == board[5]) return player;
	else if (board[6] == board[7] && board[7] == board[8]) return player;

	// Check Column Wins //
    else if (board[0] == board[3] && board[3] == board[6]) return player;
    else if (board[1] == board[4] && board[4] == board[7]) return player;
    else if (board[2] == board[5] && board[5] == board[8]) return player;

     //Check Diagonals //
    else if (board[0] == board[4] && board[4] == board[8]) return player;
    else if (board[2] == board[4] && board[4] == board[6]) return player;

    else return FALSE;
}
#endif 
