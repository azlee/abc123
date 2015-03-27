#include <string>
#include "board0.h"
#include "board.h"
#include <iostream>
#include <fstream>

void Board0::updateBoard() { // fill in empty squares
	int numEmptySquares = 0; // recorded for each column
	Square *temp;
	for (int j =0; j < 10; j++ {
		for (int i = 9; i != -1; i--) {
			temp = theBoard[i][j];
			if (temp->getType == '-') {
				numEmptySquares++;
				if (incr - 1 == numEmptySquares) { // then the rest of the top cells in that column must be empty
				// call some function to generate random squares for these cells.
					//
					//
					// Implement..
					//
					//
				}
				else { // recurse up til we find a non empty square and then set temp to that square's properties
					 // and delete the properties of that non empty square
					for (int incr = 1; incr - i >= 0; incr++) { 
						if (theBoard[i - incr][j]->getType() != '-') { // square is not empty
							temp->setType(thenBoard[i-incr][j]->getType());
							theBoard[i - incr][j]->setType('-');
						}
					}
				}
			}
		}
		numEmptySquare = 0; // reset for next column
	}
}
