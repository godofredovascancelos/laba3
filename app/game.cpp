#include <iostream>
#include "game.h"

int main()
{
	int winner = FALSE;		// For winner: FALSE = 0, X = 1, O = 2

	// The Game //
	while (!winner)
	{
		DrawBoard();
    //	GetInput();
		winner = CheckWinner();

		if (player != O) player = O; else player = X;	// Switches player each turn
	}
	DrawBoard();
	if (winner == DRAW) 
		std::cout << "The game was a draw!\n";
	else 
		std::cout << "Congratulations Player " << winner << "!\nYou win!\n";	// Winner winner, chicken dinner

	// Used to hold program open after loop. May not be necessary on your system.
	std::cin.ignore();
	std::cin.get();
}
