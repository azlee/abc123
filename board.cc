#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
#include "square.h"
using namespace std;

//class Board{
//  Square *theBoard[10][10];
//  int level;
//  int score;
void Board::clearBoard(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            delete [] theBoard[i][j];
            theBoard[i][j] = NULL;
        }
    }
}

//public:
Board::Board():score(0), leftoverLen(0) {}

Board::Board(ifstream &f):level(0),score(0){
    string aline;
    for(int i=0;i<10;i++){
        getline(f,aline);
        //cout << aline << " this is aline" << endl;
        istringstream ss1(aline);
        for(int j=0;j<10;j++){
            int c;
            char s,t;
            ss1 >> s >> t >> c;
            theBoard[i][j] = new Square(i,j,c,s,t);
        }
    }
    f >> leftover;
    cout << leftover << endl;
}

// getters & setters
int Board::getScore() {
	return score;
}

void Board::setScore(int incr) {
	score += incr;
}

void Board::swap(int r, int c, char z) {
	int tempColor;
	int newR, newC;
	char tempType, tempSpecial;
	bool locked1;
	if (z == 'n') { //north
		newR = r-1;
		newC = c;
	}
	else if (z == 's') { //south
		newR = r + 1
		newC = c;
	}
	else if (z == 'w') { //west
		newR = r;
		newC = c - 1;
	}
	else if (z == 'e') { //east
		newR = r;
		newC = c + 1;
	}
	//swap the sqaures 
	tempColor = theBoard[r][c]->getColour();
	tempType = theBoard[r][c]->getType();
	tempSpecial = theBoard[r][c]->getSpecial();
	locked1 = theBoard[r][c]->getLocked();

	delete [] theBoard[r][c];
	theBoard[r][c] = new Square(r, c, theBoard[newR][newC]->getColour(),theBoard[newR][newC]->getType, theBoard[newR][newC]->special);
	theBoard[r][c]->setLocked(theBoard[newR][newC]->getLocked());
	//mainBoard[r-1][c]->setPosition(newR, newC);

	delete [] theBoard[newR][newC];
	theBoard[newR][newC] = new Square(newR, newC, tempColour, tempType, tempSpecial);
	theBoard[newR][newC]->setLocked(locked1);
	//mainBoard[r-1][c]->setPosition(newR, newC);

	if (checkMatch()) {
		resolveMatches();
	}
}

bool validMove(int r, int c, char d) {
	int tempColor;
	int newR, newC;
	if (z == 'n') { //north
		newR = r-1;
		newC = c;
	}
	else if (z == 's') { //south
		newR = r + 1
		newC = c;
	}
	else if (z == 'w') { //west
		newR = r;
		newC = c - 1;
	}
	else if (z == 'e') { //east
		newR = r;
		newC = c + 1;
	}
	Square *tempBoard = new Square[10][10];
	for (int i = 0; i<10; i++) { // set the tempBoard square colours
		for (int j =0; j<10; j++) {
			tempBoard[i][j]->setColour(theBoard[i][j]->getColour());
		}
	}
	// swap the cells color
	tempColour = theBoard[r][c]->getColour();
	tempBoard[r][c]->setColour(theBoard[r][c]->getColour());
	tempBoard[newR][newC]->setColour(tempColour);
	
	
	// check for match of 3 in the tempBoard 
	int color1, color2, color3;
	// check all rows for row of 3 squares of same colour
	for (int i=0; i < 10; i++) {
		for (int j=0; j < 8; j++) {
			color1 = tempBoard[i][j]->getColour();
			color2 = tempBoard[i][j+1]->getColour();
			color3 = tempBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3) {
				delete [] tempBoard;
				return true;
			}
		}
	}
	// check all coloumns for col of 3 squares of same color
	for (int j=0; j<10: j++) {
		for (int i=0; i<8; i++) {
			color1 = tempBoard[i][j]->getColour();
			color2 = tempBoard[i+1][j]->getColour();
			color3 = tempBoard[i + 2][j]->getColour();
			if (color1 == color2 && color2 == color3) {
				delete tempBoard;
				return true;
			}
		}
	}
	delete [] tempBoard;
	return false;
}

bool Board::checkMatch() {
	// check for match of 3 in the board 
	int color1, color2, color3;
	// check all rows for row of 3 squares of same colour
	for (int i=0; i < 10; i++) {
		for (int j=0; j < 8; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i][j+1]->getColour();
			color3 = theBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3) {
				return true;
			}
		}
	}
	// check all coloumns for col of 3 squares of same color
	for (int j=0; j<10: j++) {
		for (int i=0; i<8; i++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i + 2][j]->getColour();
			if (color1 == color2 && color2 == color3) {
				return true;
			}
		}
	}
	return false;
}

// check for 5 match horizontally
void Board::check5Row() {
	int color1, color2, color3, color4, color5;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=9; i != -1; i--) {
		for (int j=0; j < 6; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i][j+1]->getColour();
			color3 = theBoard[i][j+2]->getColour();
			color4 = theBoard[i][j+3]->getColour();
			color5 = theBoard[i][j+4]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 5; k++) {
					if (theBoard[i][j+k]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j+k]->getType() == 'u') { 
						upright = true;
						uprightC = j+k;
					}
					else if (theBoard[i][j+k]->getType() == 's') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i][j+k]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('_'); // set squares to '-' type
				theBoard[i][j+1]->setType('_');
				theBoard[i][j+2]->setType('p'); // set center square to 'p' type
				theBoard[i][j+3]->setType('_');
				theBoard[i][j+4]->setType('_');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

// check for 5 match vertically
void Board::check5Column() {
	int color1, color2, color3, color4, color5;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int j=0; j < 10; j++) {
		for (int i=5; i != -1; i--) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i+3][j]->getColour();
			color5 = theBoard[i+4][j]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 5; k++) {
					if (theBoard[i+k][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+k][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+k][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+k][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+k;
					}
				}
				theBoard[i][j]->setType('_'); // set squares to '-' type
				theBoard[i+1][j]->setType('_');
				theBoard[i+2][j]->setType('p'); // set center square to 'p' type
				theBoard[i+3][j]->setType('_');
				theBoard[i+4][j]->setType('_');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

// check for 4 match horizontally
void Board::check4Row() {
	int color1, color2, color3, color4;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=9; i != -1; i--) {
		for (int j=0; j < 7; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i][j+1]->getColour();
			color3 = theBoard[i][j+2]->getColour();
			color4 = theBoard[i][j+3]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 4; k++) {
					if (theBoard[i][j+k]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j+k]->getType() == 'u') { 
						upright = true;
						uprightC = j+k;
					}
					else if (theBoard[i][j+k]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i][j+k]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('_'); // set squares to '-' type
				theBoard[i][j+1]->setType('l'); // set type to 'l' type
				theBoard[i][j+2]->setType('_');
				theBoard[i][j+3]->setType('_');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

// check for 4 match vertically
void Board::check4Column() {
	int color1, color2, color3, color4;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int j=0; j < 10; j++) {
		for (int i=6; i != -1; i--) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i+3][j]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 4; k++) {
					if (theBoard[i+k][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+k][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+k][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+k][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+k;
					}
				}
				theBoard[i][j]->setType('_'); // set squares to '-' type
				theBoard[i+1][j]->setType('_');
				theBoard[i+2][j]->setType('l'); // set square to 'l' type
				theBoard[i+3][j]->setType('_');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

void Board::checkL1() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 7; i != -1; i--) {
		for (int j =0; j<8; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i][j+1]->getColour();
			color5 = theBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i+i2][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+i2][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+i2][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+i2][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=0; j2 < 2; j2++) {
					if (theBoard[i][j + j2]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j + j2]->getType() == 'u') {
						upright = true;
						uprightC = j + j2;
					}
					else if (theBoard[i][j+j2]->getType() == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j+j2]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i+1][j]->setType('_');
				theBoard[i+2][j]->setType('_');
				theBoard[i][j+1]->setType('_');
				theBoard[i][j+2]->setType('_');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

void Board::checkL2() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 9; i > 1; i--) {
		for (int j =0; j<8; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i-1][j]->getColour();
			color3 = theBoard[i-2][j]->getColour();
			color4 = theBoard[i][j+1]->getColour();
			color5 = theBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i-i2][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i-i2][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i-i2][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i-i2][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j + j2]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j + j2]->getType() == 'u') {
						upright = true;
						uprightC = j + j2;
					}
					else if (theBoard[i][j+j2]->getType() == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j+j2]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i-1][j]->setType('_');
				theBoard[i-2][j]->setType('_');
				theBoard[i][j+1]->setType('_');
				theBoard[i][j+2]->setType('_');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

void Board::checkL3() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 9; i > 1; i--) {
		for (int j =2; j<10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i-1][j]->getColour();
			color3 = theBoard[i-2][j]->getColour();
			color4 = theBoard[i][j-1]->getColour();
			color5 = theBoard[i][j-2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i-i2][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i-i2][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i-i2][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i-i2][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j - j2]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j - j2]->getType() == 'u') {
						upright = true;
						uprightC = j - j2;
					}
					else if (theBoard[i][j-j2]->getType() == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j-j2]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i-1][j]->setType('_');
				theBoard[i-2][j]->setType('_');
				theBoard[i][j-1]->setType('_');
				theBoard[i][j-2]->setType('_');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	}
}

void Board::checkL4() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 7; i != -1; i--) {
		for (int j =2; j<10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i][j-1]->getColour();
			color5 = theBoard[i][j-2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i+i2][j]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+i2][j]->getType() == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+i2][j]->getType() == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+i2][j]->getType() == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j - j2]->getType() == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j - j2]->getType() == 'u') {
						upright = true;
						uprightC = j - j2;
					}
					else if (theBoard[i][j-j2]->getType() == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j-j2]->getType() == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); // set to unstable square
				theBoard[i+1][j]->setType('_');
				theBoard[i+2][j]->setType('_');
				theBoard[i][j-1]->setType('_');
				theBoard[i][j-2]->setType('_');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('_');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('_');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('_')
					}
				}
			}
		}
	} 
}

void Board::resolveMatches() {
	while (checkMatch()) {
		check5Row();
		check5Column();
		check4Row();
		check4Column();
		checkL1();
		checkL2();
		checkL3();
		checkL4();
	}
	// add method to fill in all the squares with '-' type
}

Board::~Board(){
    clearBoard();
//  delete theBoard;
}

ostream& operator<<(ostream &out, const Board &b){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            out << *(b.theBoard[i][j]) << " ";
        }
        out << endl;
    }
    return out;
} 

