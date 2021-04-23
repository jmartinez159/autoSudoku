/*
	AutoSudoku Class
	-We will be using a 2D array to store all our input for the sudoku puzzle
	-First we will initialize our array to be full with zeros.
		-This is to mark that at if at certain index contains a 0 then this spot
		 is empty.
	-Next is initializing the puzzle by having some sort of external input to hold
	 values (1-9 only) at certain indexes throughout our array. The outcome of this
	 should represent something similar to a sudoku puzzle. 
	-After, we would need to implement the rules of sudoku.
		- Rows, Columns, and Box(3x3) all can not have duplicates.
	-When the above is complete is when the program can start inputting values
	 into the array by just plugging in values as long as they follow the 3 rules
	-Program should be able to find a solution just by inputting values (I hope...) 
*/

#ifndef AUTOSUDOKU_H
#define AUTOSUDOKU_H
#include <iostream>

using namespace std;

class autoSudoku
{
public:
	//Default Contructor
	//-Initializes our 2D array with default values
	autoSudoku();

	//Deconstructor
	~autoSudoku();

	//Member Functions
		
	//Prints Board
	void print();

private:

	//Data Structure (holds values and simulates sudoku)
	int board[9][9];

	//Holds size of our board
	int boardSize;

};

#endif // !autoSudoku
