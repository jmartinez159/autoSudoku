#include "autosudoku.h"

//Constructor
autoSudoku::autoSudoku()
{
	
	//Initializing everything in the board to 0
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			board[r][c] = 0;
		}
	}
	//Setting size to 0
	boardSize = 0;

}


//Deconstructor
autoSudoku::~autoSudoku()
{
	boardSize = 0;
}




//	- This Function just prints the current board.
void autoSudoku::print()
{
	for (int rIndex = 0; rIndex < 9; rIndex++)
	{
		for (int cIndex = 0; cIndex < 9; cIndex++)
		{
			cout << board[rIndex][cIndex] << ' ';
			if (cIndex % 3 == 2)
				cout << "| ";
		}
		cout << endl;
		if (rIndex % 3 == 2)
		{
			cout << "-----------------------" <<endl;
		}
	}
}

bool autoSudoku::rowCheck(int val, int column)
{
	for (int i = 0; i < 9; i++)
	{
		//If we find a match return false - meaning theres a duplicate
		if (board[i][column] == val)
			return false;
	}
	//If we make it this far I'm assuming there's no matches 
	return true;
}

bool autoSudoku::columnCheck(int val, int row)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[row][i] == val)
			return false;
	}

	return true;
}


//Function gets a row index or column index to determine where
//the first row of the 3x3 box we are checking is.
int autoSudoku::startingPos(int index)
{
	int rePosition = index % 3;
	rePosition = index - rePosition;
	return rePosition;
}

bool autoSudoku::boxCheck(int val, int row, int column)
{
	//Holds starting index of the row for 1 out of 9 3x3 boxes
	int boxRow = startingPos(row);

	//Holds starting index of the column for 1 out of 9 3x3 boxes
	int boxColumn = startingPos(column);

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			//If we find a duplucate returns false
			if (board[boxRow + r][boxColumn + c] == val)
				return false;
		}
	}

	//If we exit loop no duplicates were found in our 3x3 box 
	return true;
}

