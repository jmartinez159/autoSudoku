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


void autoSudoku::solveIt()
{
	
	

	//Need to traverse through the entire board
	for (int rowIndex = 0; rowIndex < 9; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < 9; columnIndex++)
		{
			//Checking to see that at current position there is an empty spot
			if (board[rowIndex][columnIndex] == 0)
			{
				//Empty Space in our puzzle opens for a possible solution  

				//Count to see how many solutions there are at one specific position 
				int count = 0;
				int solution;


				//This loop goes thru all the possible solutions (1 - 9) and calls
				//validateInput function to check for valid solutions 
				for (int i = 1; i < 10; i++)
				{
					if (validateInput(i, rowIndex, columnIndex))
					{

						//Updates our count to see how many solutions we found 
						count++;

						//Sets solution to the last solution found at i
						solution = i;
					}
				}

				//cout << "Count : " << count << "  Solution: " << solution

				//If count is equal to one that means we found the one only solution
				//Next is to plug that into our board as a valid answer
				if (count == 1)
				{
					board[rowIndex][columnIndex] = solution;
					boardSize++;
				}


				//End of this position moving to find the next empty position on our board. 
			}


		}


	}


}

bool autoSudoku::isSolved()
{
	//board is full of solutions
	if (boardSize == 81)
		return true;
	//Not full not complete
	return false;
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

bool autoSudoku::columnCheck(int val, int column)
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

bool autoSudoku::rowCheck(int val, int row)
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


//Function is responsible validating the input at a certain index
//in able to follow the rules of the game	
bool autoSudoku::validateInput(int val, int row, int col)
{
	//Out of range value
	if (val < 1 || val > 9)
		return false;

	//Space is not empty
	if (board[row][col] != 0)
		return false;

	//Checks to see if it is a possible solution 
	if (!rowCheck(val, row))
		return false;
	if (!columnCheck(val, col))
		return false;
	if (!boxCheck(val, row, col))
		return false;

	//Passes tests
	return true;
}


//Function inputs values into the board
void autoSudoku::setValue(int val, int row, int col)
{
	if (!validateInput(val, row, col))
		return;

	board[row][col] = val;
	boardSize++;

	return;
}

