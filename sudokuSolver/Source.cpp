#include <iostream>
#include "autosudoku.h"

using namespace std;

int testing();

int testing2();

int main()
{
	testing();
	return 0;
}

int testing()
{
	autoSudoku a;
	//a.print();

	//		input, row, col
	a.setValue(5, 0, 0);
	a.setValue(4, 0, 2);
	a.setValue(7, 0, 7);
	a.setValue(6, 1, 1);
	a.setValue(9, 1, 7);
	a.setValue(3, 1, 8);
	a.setValue(7, 2, 2);
	a.setValue(3, 2, 4);
	a.setValue(6, 2, 6);
	a.setValue(2, 2, 7);
	a.setValue(5, 2, 8);
	a.setValue(2, 3, 1);
	a.setValue(9, 3, 5);
	a.setValue(7, 3, 6);
	a.setValue(7, 4, 0);
	a.setValue(5, 4, 1);
	a.setValue(3, 4, 2);
	a.setValue(8, 4, 4);
	a.setValue(9, 4, 6);
	a.setValue(6, 4, 7);
	a.setValue(4, 4, 8);
	a.setValue(1, 5, 2);
	a.setValue(4, 5, 3);
	a.setValue(3, 5, 7);
	a.setValue(6, 6, 0);
	a.setValue(8, 6, 1);
	a.setValue(9, 6, 2);
	a.setValue(4, 6, 4);
	a.setValue(1, 6, 6);
	a.setValue(1, 7, 0);
	a.setValue(4, 7, 1);
	a.setValue(8, 7, 7);
	a.setValue(7, 8, 1);
	a.setValue(2, 8, 6);
	a.setValue(9, 8, 8);
	
	while (!a.isSolved())
	{
		a.solveIt();
	}



	a.print();

	cout << "Passed easy test" << endl;
	return 0;
}

//This test does not work yet for medium puzzles

int testing2()
{
	autoSudoku a;
	a.setValue(6, 0, 2);
	a.setValue(8, 0, 5);
	a.setValue(3, 0, 7);
	a.setValue(9, 0, 8);
	a.setValue(7, 1, 0);
	a.setValue(3, 1, 4);
	a.setValue(1, 1, 7);
	a.setValue(5, 2, 2);
	a.setValue(6, 2, 3);
	a.setValue(1, 2, 4);
	a.setValue(9, 2, 5);
	a.setValue(7, 2, 7);
	a.setValue(3, 3, 5);
	a.setValue(4, 3, 6);
	a.setValue(8, 3, 8);
	a.setValue(9, 4, 3);
	a.setValue(1, 4, 5);
	a.setValue(9, 5, 0);
	a.setValue(3, 5, 2);
	a.setValue(2, 5, 3);
	a.setValue(6, 6, 1);
	a.setValue(1, 6, 3);
	a.setValue(2, 6, 4);
	a.setValue(7, 6, 5);
	a.setValue(9, 6, 6);
	a.setValue(1, 7, 1);
	a.setValue(9, 7, 4);
	a.setValue(2, 7, 8);
	a.setValue(4, 8, 0);
	a.setValue(9, 8, 1);
	a.setValue(3, 8, 3);
	a.setValue(1, 8, 6);

	a.solveIt();
	a.solveIt();
	a.solveIt();
	a.solveIt();
	a.print();

	return 0;
}
