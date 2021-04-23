#include "autosudoku.h"

//Constructor
autoSudoku::autoSudoku()
{
	//rIndex - is a variable used to hold a row index
	//cIndex - is a variable used to hold a column index
	for(int rIndex = 0; rIndex < 9; rIndex++)
	{
		for (int cIndex = 0; cIndex < 9; cIndex++)
		{
			//Initializing board array to values of only 0 as default  
			board[rIndex][cIndex] = 0;
		}
	}

	//Setting size to 0
	boardSize = 0;

}


//Deconstructor
autoSudoku::~autoSudoku()
{

}


//	- This Function just prints the current board.
void autoSudoku::print()
{
	for (int rIndex = 0; rIndex < 9; rIndex++)
	{
		for (int cIndex = 0; cIndex < 9; cIndex++)
		{
			cout << board[rIndex][cIndex] << ' ';
		}
		cout << endl;
	}
}
