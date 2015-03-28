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
        	if (temp->getColour() == '_') {
                numEmptySquares++;
                if (i- 1 == numEmptySquares) { // then the rest of the top cells in that column must be empty
                    int colour;
                    if (numGenerated < leftoverLen) {
                        colour = leftover [numGenerated];
                        numGenerated++;
                    }
                    else {
                        numGenerated = 0;
                        colour = leftover[numGenerated];

                    }
                    temp->changeSquare(colour,type);
                }
                else { // recurse up til we find a non empty square and then set temp to that square's properties
                     // and delete the properties of that non empty square
                    for (int incr = 1; incr - i >= 0; incr++) { 
                        if (theBoard[i - incr][j]->getColour() != '_') { // square is not empty
                            temp->setType(theBoard[i-incr][j]->getType());
                            temp->setColour(theBoard[i-incr][j]->getColour());
                            theBoard[i - incr][j]->setColour('_');
                            theBoard[i-incr][j]->setType('_');
                        }
                    }
                }
            }
        }
        numEmptySquare = 0; // reset for next column
    }
}
