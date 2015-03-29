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
Board::Board():level(0),score(0){}

//initializer for Board0
Board::Board(ifstream &f):level(0),score(0){
    string aline;
    for(int i=0;i<10;i++){
        getline(f,aline);
        istringstream ss1(aline);
        for(int j=0;j<10;j++){
            int c;
            char s,t;
            ss1 >> s >> t >> c;
            theBoard[i][j] = new Square(i,j,c,t,s);
        }
    }
    f >> leftover;
}

string Board::getLeftover() {
	return leftover;
}

int Board::hint(){
    int first,second,third;
    //fix the first row
        for(int j=0;j<10;j++){
            if(j==0){
                first = theBoard[1][j]->getColour();
                second = theBoard[0][j+1]->getColour();
                third = theBoard[0][j+2]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
            //second = theBoard[2][j]->getColour();
                third = theBoard[2][j]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
            }
            else if(j==1){
                first = theBoard[1][j]->getColour();
                second = theBoard[0][j+1]->getColour();
                third = theBoard[0][j-1]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
                third = theBoard[0][j+2]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
                first = theBoard[0][j-1]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
                second = theBoard[1][j]->getColour();
                third = theBoard[2][j]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
                first = theBoard[0][j+1]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
                }
            }
            else if(j==9){
                first = theBoard[1][j]->getColour();
                second = theBoard[0][j-1]->getColour();
                third = theBoard[0][j-2]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                   return 1;
                }
                second = theBoard[0][j-1]->getColour();
                third = theBoard[2][j]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                   return 1;
                }
            }
            else if(j==8){
                first = theBoard[1][j]->getColour();
                second = theBoard[0][j+1]->getColour();
                third = theBoard[0][j-1]->getColour();
                if(first==second&&second==third){
                    cout << "0 " << j << endl;
                    return 1;
	            }
	            second = theBoard[0][j-2]->getColour();
	            if(first==second&&second==third){
	                cout << "0 " << j << endl;
	                return 1;
	            }
	            first = theBoard[0][j+1]->getColour();
	            if(first==second&&second==third){
	                cout << "0 " << j << endl;
	                return 1;
	            }
	            second = theBoard[1][j]->getColour();
	            third = theBoard[2][j]->getColour();
	            if(first==second&&second==third){
	                cout <<  "0 " << j << endl;
	                return 1;
	            }
	            first = theBoard[0][j-1]->getColour();
	            if(first==second&&second==third){
	                cout << "0 " << j << endl;
	                return 1;
	            }
	        }
	        else{
	            first = theBoard[1][j]->getColour();
	            second = theBoard[0][j+1]->getColour();
	            third = theBoard[0][j-1]->getColour();
	            if(first==second&&second==third){
	                cout << "0 " << j << endl;
	                return 1;
	            }
            second = theBoard[0][j-2]->getColour();
            if(first==second&&second==third){
                cout << "0 " << j << endl;
                return 1;
            }
            second = theBoard[0][j+1]->getColour();
            third = theBoard[0][j+2]->getColour();
            if(first==second&&second==third){
                cout << "0 " << j << endl;
                return 1;
            }
            second = theBoard[2][j]->getColour();
            third = theBoard[0][j+1]->getColour();
            if(first==second&&second==third){
                cout << "0 " << j << endl;
                return 1;
            }
            third = theBoard[0][j-1]->getColour();
            if(first==second&&second==third){
                cout << "0 " << j << endl;
                return 1;
            }
        }
    }//done with first row
    //fix last row
    for(int j=0;j<10;j++){
        if(j==0){
            first = theBoard[8][j]->getColour();
            second = theBoard[9][j+1]->getColour();
            third = theBoard[9][j+2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j+1]->getColour();
            second = theBoard[7][j]->getColour();
            third = theBoard[8][j]->getColour();
            if(first==second&&second==third){
                cout << "0 " << j << endl;
                return 1;
            }
        }
        else if(j==1){
            first = theBoard[8][j]->getColour();
            second = theBoard[9][j+1]->getColour();
            third = theBoard[9][j-1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            third = theBoard[9][j+2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j-1]->getColour();
            second = theBoard[8][j]->getColour();
            third = theBoard[7][j]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j+1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
        }
        else if(j==9){
            first = theBoard[8][j]->getColour();
            second = theBoard[9][j-1]->getColour();
            third = theBoard[9][j-2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j-1]->getColour();
            second = theBoard[8][j]->getColour();
            third = theBoard[7][j]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
        }
        else if(j==8){
            first = theBoard[8][j]->getColour();
            second = theBoard[9][j+1]->getColour();
            third = theBoard[9][j-1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            second = theBoard[9][j-2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j+1]->getColour();
            second = theBoard[8][j]->getColour();
            third = theBoard[7][j]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j-1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
        }
        else{
            first = theBoard[8][j]->getColour();
            second = theBoard[9][j+1]->getColour();
            third = theBoard[9][j-1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            second = theBoard[9][j-2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            second = theBoard[9][j+1]->getColour();
            third = theBoard[9][j+2]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j+1]->getColour();
            second = theBoard[8][j]->getColour();
            third = theBoard[7][j]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
            first = theBoard[9][j-1]->getColour();
            if(first==second&&second==third){
                cout << "9 " << j << endl;
                return 1;
            }
        }
    }//done with last row
    //need to do the first and last column
    for(int i=1;i<9;i++){
        //check for horizontal match without border (mid)
        for(int j=1;j<9;j++){
            if(i==1&&j==1){
                //horizontal
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i][j-1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                //vertical
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i][j-1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
            }
            else if(i==1&&j==8){
                //horizontal
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                //vertical
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i+1][j]->getColour();
                second = theBoard[i+2][j]->getColour();
                third = theBoard[i][j+2]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
            }
            else if(i==8&&j==1){
                //horizontal
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j+1]->getColour();
                second = theBoard[i][j+2]->getColour();
                third = theBoard[i][j-1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                //vertical
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i][j-1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
            }
            else if(i==8&&j==8){
                //horizontal
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i-1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i][j-1]->getColour();
                second = theBoard[i][j-2]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                //vertical
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i][j+1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i][j-1]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
                first = theBoard[i-1][j]->getColour();
                second = theBoard[i-2][j]->getColour();
                third = theBoard[i+1][j]->getColour();
                if(first==second&&second==third){
                    cout << i << " " << j << endl;
                    return 1;
                }
            }
            first = theBoard[i][j-1]->getColour();
            second = theBoard[i-1][j]->getColour();
            third = theBoard[i][j+1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            second = theBoard[i+1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            //check for vertical match without border (mid)
            first = theBoard[i-1][j]->getColour();
            second = theBoard[i][j+1]->getColour();
            third = theBoard[i+1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            second = theBoard[i][j-1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
        }
    }//end of a long ass loop
    
    //checking tail 3-match
    for(int i=2;i<7;i++){
        for(int j=2;j<7;i++){
            //north
            first = theBoard[i-2][j]->getColour();
            second = theBoard[i-1][j]->getColour();
            third = theBoard[i][j-1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            third = theBoard[i][j+1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            //south
            first = theBoard[i+2][j]->getColour();
            second = theBoard[i+1][j]->getColour();
            third = theBoard[i][j-1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            third = theBoard[i][j+1]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            //east
            first = theBoard[i][j+1]->getColour();
            second = theBoard[i][j+2]->getColour();
            third = theBoard[i-1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            third = theBoard[i+1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            //west
            first = theBoard[i][j-1]->getColour();
            second = theBoard[i][j-2]->getColour();
            third = theBoard[i-1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
            third = theBoard[i+1][j]->getColour();
            if(first==second&&second==third){
                cout << i << " " << j << endl;
                return 1;
            }
        }
    }
    
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
        newR = r + 1;
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
    theBoard[r][c] = new Square(r, c, theBoard[newR][newC]->getColour(),theBoard[newR][newC]->getType(), theBoard[newR][newC]->getSpecial());
    theBoard[r][c]->setLocked(theBoard[newR][newC]->getLocked());

    delete [] theBoard[newR][newC];
    theBoard[newR][newC] = new Square(newR, newC, tempColor, tempType, tempSpecial);
    theBoard[newR][newC]->setLocked(locked1);
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
    for (int j=0; j<10; j++) {
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
	int numUpright=0;
    int uprightC[5]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int numUnstable=0;
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
            if (color1 != 6 && color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 5; k++) {
                    if (theBoard[i][j+k]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'v') { 
						upright = true;
                        uprightC[numUpright] = j+k;
						numUpright++;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'h') {
                        lateral = true;
                        lateralR = i;
                        theBoard[i][j+k]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '-' type
                theBoard[i][j+1]->setColour(6);
                theBoard[i][j+2]->setType('p'); // set center square to 'p' type
                theBoard[i][j+3]->setColour(6);
                theBoard[i][j+4]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) 
                                theBoard[i2][j2]->setColour(6);
								theBoard[i2][j2]->setType('_');
                            }
                    }
					psychedelic = false;
                }
                
                if (upright == true) { 
					for (int u1=0; u1 < numUpright; u1++) { // set the entire column to type '-'
                        int j4 = uprightC[u1];
						for (int j3 = 0; j3 < 10; j3++) {
							theBoard[j3][j4]->setColour(6);
							theBoard[j3][j4]->setType('_');
                    	}
                	}
					upright=false;
				}
                if (lateral == true) {
                    for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                        theBoard[lateralR][i3]->setColour(6);
						theBoard[lateralR][i3]->setType('_');
                    }
					lateral = false;
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
	int numLateral = 0;
    int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR[5]; // if a lateralSquare is involved in a match then keep track of it's row
                // to later rid all those cells in that row
    // check all rows for row of 5 squares of same color
    for (int j=0; j < 10; j++) {
        for (int i=5; i != -1; i--) {
            color1 = theBoard[i][j]->getColour();
            color2 = theBoard[i+1][j]->getColour();
            color3 = theBoard[i+2][j]->getColour();
            color4 = theBoard[i+3][j]->getColour();
            color5 = theBoard[i+4][j]->getColour();
            if (color1 != 6 && color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 5; k++) {
                    if (theBoard[i+k][j]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'v') { 
                        upright = true;
                        uprightC = j;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i+k][j];
                    }
                    else if (theBoard[i+k][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+k;
						numLateral++;
                        theBoard[i+k][j]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '-' type
                theBoard[i+1][j]->setColour(6);
                theBoard[i+2][j]->setType('p'); // set center square to 'p' type
                theBoard[i+3][j]->setColour(6);
                theBoard[i+4][j]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
								theBoard[i2][j2]->setType('_');
                            }
                        }
                    }
					psychedelic = false;
                }
                if (upright == true) {
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][uprightC]->setColour(6);
						theBoard[j3][uprightC]->setType('_');
                    }
					upright = false;
                }
                if (lateral == true) {
					for (int n = 0; n< numLateral; n++) {
						int row = lateralR[n];
							for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                        		theBoard[row][i3]->setColour(6);
								theBoard[row][i3]->setType('_');
                    		}
                	}
				lateral = false;
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
    int numUpright=0;
    int uprightC[4]; // if an uprightSquare is involved in a match then keep track of it's column 
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
            if (color1 !=6 && color1 == color2 && color2 == color3 && color3 == color4) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 4; k++) {
                    if (theBoard[i][j+k]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'v') { 
                        upright = true;
                        uprightC[numUpright] = j+k;
                        numUpright++;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'h') {
                        lateral = true;
                        lateralR = i;
                        theBoard[i][j+k]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '-' type
                theBoard[i][j+1]->setType('h'); // set type to 'h' lateral type
                theBoard[i][j+2]->setColour(6);
                //theBoard[i][j+1]->setColour(6);
                theBoard[i][j+3]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                 theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
                    for (int u1=0; u1 < numUpright; u1++) { // set the entire column to type '-'
                        int j4 = uprightC[u1];
                        for (int j3 = 0; j3 < 10; j3++) {
                            theBoard[j3][j4]->setColour(6);
                            theBoard[j3][j4]->setType('_');
                        }
                    }
                    upright=false;
                }
                if (lateral == true) {
                    for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                        theBoard[lateralR][i3]->setColour(6);
                    }
                    lateral = false;
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
    int lateralR[5]; // if a lateralSquare is involved in a match then keep track of it's row
                // to later rid all those cells in that row
    int numLateral=0;
    int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    // check all rows for row of 5 squares of same color
    for (int j=0; j < 10; j++) {
        for (int i=6; i != -1; i--) {
            color1 = theBoard[i][j]->getColour();
            color2 = theBoard[i+1][j]->getColour();
            color3 = theBoard[i+2][j]->getColour();
            color4 = theBoard[i+3][j]->getColour();
            if (color1 != 6 && color1 == color2 && color2 == color3 && color3 == color4) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 4; k++) {
                    if (theBoard[i+k][j]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'v') { 
                        upright = true;
                        uprightC = j;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+k;
                        numLateral++;
                        theBoard[i+k][j]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '_' type
                theBoard[i+1][j]->setColour(6);
                theBoard[i+2][j]->setType('v'); // set square to 'v' upright type
                theBoard[i+3][j]->setColour(6);
                //theBoard[i+2][j]->setColour(6);
                theBoard[i+1][j]->setColour(6);
                theBoard[i+3][j]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][uprightC]->setColour(6);
                    }
                    upright = false;
                }
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
                }
            }
        }
    }
}

// check for 3 match horizontally
void Board::check3Row() {
    int color1, color2, color3, color4;
    // keep track of whether one of the squares involved in the match was a different type of square 
    bool psychedelic = false;
    bool unstable = false;
    bool upright = false;
    bool lateral = false;
    int numUpright=0;
    int uprightC[3]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
                // to later rid all those cells in that row
    // check all rows for row of 5 squares of same color
    for (int i=9; i != -1; i--) {
        for (int j=0; j < 8; j++) {
            color1 = theBoard[i][j]->getColour();
            color2 = theBoard[i][j+1]->getColour();
            color3 = theBoard[i][j+2]->getColour();
            if (color1 != 6 && color1 == color2 && color2 == color3 && color3 == color4) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 3; k++) {
                    if (theBoard[i][j+k]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'v') { 
                        upright = true;
                        uprightC[numUpright] = j+k;
                        numUpright++;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i][j+k]->setType('_');
                    }
                    else if (theBoard[i][j+k]->getType() == 'h') {
                        lateral = true;
                        lateralR = i;
                        theBoard[i][j+k]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '-' type
                theBoard[i][j+1]->setType('h'); // set type to 'h' lateral type
                theBoard[i][j+2]->setColour(6);
                //theBoard[i][j+1]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                 theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
                    for (int u1=0; u1 < numUpright; u1++) { // set the entire column to type '-'
                        int j4 = uprightC[u1];
                        for (int j3 = 0; j3 < 10; j3++) {
                            theBoard[j3][j4]->setColour(6);
                            theBoard[j3][j4]->setType('_');
                        }
                    }
                    upright=false;
                }
                if (lateral == true) {
                    for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                        theBoard[lateralR][i3]->setColour(6);
                    }
                    lateral = false;
                }
            }
        }
    }
}

// check for 3 match vertically
void Board::check3Column() {
    int color1, color2, color3, color4;
    // keep track of whether one of the squares involved in the match was a different type of square 
    bool psychedelic = false;
    bool unstable = false;
    bool upright = false;
    bool lateral = false;
    int lateralR[3]; // if a lateralSquare is involved in a match then keep track of it's row
                // to later rid all those cells in that row
    int numLateral=0;
    int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    // check all rows for row of 5 squares of same color
    for (int j=0; j < 10; j++) {
        for (int i=6; i != -1; i--) {
            color1 = theBoard[i][j]->getColour();
            color2 = theBoard[i+1][j]->getColour();
            color3 = theBoard[i+2][j]->getColour();
            if (color1 != 6 && color1 == color2 && color2 == color3 && color3 == color4) { //check for match
                // check if any of the squares in the match are a different type
                for (int k=0; k < 3; k++) {
                    if (theBoard[i+k][j]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'v') { 
                        upright = true;
                        uprightC = j;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i+k][j]->setType('_');
                    }
                    else if (theBoard[i+k][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+k;
                        numLateral++;
                        theBoard[i+k][j]->setType('_');
                    }
                }
                theBoard[i][j]->setColour(6); // set squares to '_' type
                theBoard[i+1][j]->setColour(6);
                theBoard[i+2][j]->setType('v'); // set square to 'v' upright type
                theBoard[i+3][j]->setColour(6);
                //theBoard[i+2][j]->setColour(6);
                theBoard[i+1][j]->setColour(6);
                theBoard[i+3][j]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][uprightC]->setColour(6);
                    }
                    upright = false;
                }
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
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
    int numUpright = 0;
    int numLateral = 0;
    int uprightC[3]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR[3]; // if a lateralSquare is involved in a match
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
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i+i2][j]->getType() == 'v') { 
                        if (upright == false) {
                          uprightC[numUpright]= j;
                          numUpright++;
                          upright = true;
                        }
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i+i2][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i+i2][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+i2;
                        numLateral++;
                        theBoard[i+i2][j]->setType('_');
                    }
                }
                for (int j2=0; j2 < 2; j2++) {
                    if (theBoard[i][j + j2]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j+j2]->setType('_');
                    }
                    else if (theBoard[i][j + j2]->getType() == 'v') {
                        upright = true;
                        uprightC[numUpright] = j + j2;
                        numUpright++;
                        theBoard[i][j+j2]->setType('_');
                    }
                    else if (theBoard[i][j+j2]->getType() == 'b') {
                        unstable = true;
                        theBoard[i][j+j2]->setType('_');
                    }
                    else if (theBoard[i][j+j2]->getType() == 'h') {
                        if (lateral == false) {
                            lateralR[numLateral] = i;
                            numLateral++;
                            lateral = true;
                        }
                        theBoard[i][j+j2]->setType('_');
                    }
                }
                theBoard[i][j]->setType('b'); //set to unstable square
                theBoard[i+1][j]->setColour(6);
                theBoard[i+2][j]->setColour(6);
                theBoard[i][j+1]->setColour(6);
                theBoard[i][j+2]->setColour(6);
                //theBoard[i][j]->setColour(6);

                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
				for (int z=0; z<numUpright; z++) {
					int col = uprightC[numUpright];
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][col]->setColour(6);
                    }
                }
				upright = false;
				}
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
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
    int numUpright = 0;
    int numLateral = 0;
    int uprightC[3]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR[3]; // if a lateralSquare is involved in a match
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
                        theBoard[i-i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'v') { 
                        if (upright == false) {
                          uprightC[numUpright]= j;
                          numUpright++;
                          upright = true;
                        }
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i-i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+i2;
                        numLateral++;
                        theBoard[i+i2][j]->setType('_');
                    }
                }
                for (int j2=1; j2 < 3; j2++) {
                    if (theBoard[i][j + j2]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j + j2]->setType('_');
                    }
                    else if (theBoard[i][j + j2]->getType() == 'v') {
                        upright = true;
                        uprightC[numUpright] = j + j2;
                        numUpright++;
                        theBoard[i][j+j2]->setType('_');
                    }
                    else if (theBoard[i][j+j2]->getType() == 'b') {
                        unstable = true;
                        theBoard[i][j+j2]->setType('_');
                    }
                    else if (theBoard[i][j+j2]->getType() == 'h') {
                        if (lateral == false) {
                            lateralR[numLateral] = i;
                            numLateral++;
                            lateral = true;
                        }
                        theBoard[i][j+j2]->setType('_');
                    }
                }
                theBoard[i][j]->setType('b'); //set to unstable square
                theBoard[i-1][j]->setColour(6);
                theBoard[i-2][j]->setColour(6);
                theBoard[i][j+1]->setColour(6);
                theBoard[i][j+2]->setColour(6);
                //theBoard[i][j]->setColour(6);

                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
				for (int x=0; x<numUpright; x++) {
					int col = uprightC[numUpright];
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][col]->setColour(6);
                    }
                    upright = false;
                }
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
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
    int numUpright = 0;
    int numLateral = 0;
    int uprightC[3]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR[3]; // if a lateralSquare is involved in a match
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
                        theBoard[i-i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'v') { 
                        if (upright == false) {
                          uprightC[numUpright]= j;
                          numUpright++;
                          upright = true;
                        }
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i-i2][j]->setType('_');
                    }
                    else if (theBoard[i-i2][j]->getType() == 'h') {
                        lateral = true;
                        lateralR[numLateral] = i+i2;
                        numLateral++;
                        theBoard[i+i2][j]->setType('_');
                    }
                }
                for (int j2=1; j2 < 3; j2++) {
                    if (theBoard[i][j - j2]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j - j2]->getType() == 'v') {
                        upright = true;
                        uprightC[numUpright] = j - j2;
                        numUpright++;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j-j2]->getType() == 'b') {
                        unstable = true;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j-j2]->getType() == 'h') {
                        if (lateral == false) {}
                            lateral = true;
                            lateralR[numLateral] = i;
                            numLateral++;
                        }
                        theBoard[i][j-j2]->setType('_');
                    }
                }
                theBoard[i][j]->setType('b'); //set to unstable square
                theBoard[i-1][j]->setColour(6);
                theBoard[i-2][j]->setColour(6);
                theBoard[i][j-1]->setColour(6);
                theBoard[i][j-2]->setColour(6);
                //theBoard[i][j]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
				for (int x=0; x<numUpright; x++) {
					int col = uprightC[numUpright];
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][col]->setColour(6);
                    }
                    upright = false;
                }
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
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
    int numUpright = 0;
    int numLateral = 0;
    int uprightC[3]; // if an uprightSquare is involved in a match then keep track of it's column 
                  // to later rid all those cells in that column 
    int lateralR[3]; // if a lateralSquare is involved in a match
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
                        theBoard[i+i2][j]->setType('_'); 
                   }
                    else if (theBoard[i+i2][j]->getType() == 'v') { 
                        if (upright==false) {
                            upright = true;
                            uprightC[numUpright] = j;
                            numUpright++;
                        }
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i+i2][j]->getType() == 'b') { // unstable square involved
                        unstable = true;
                        theBoard[i+i2][j]->setType('_');
                    }
                    else if (theBoard[i+i2][j]->getType() == 'h') {
                        lateral = true;
                        theBoard[i+i2][j]->setType('_');
                        lateralR[numLateral] = i+i2;
                        numLateral++;
                    }
                }
                for (int j2=1; j2 < 3; j2++) {
                    if (theBoard[i][j - j2]->getType() == 'p') {
                        psychedelic = true;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j - j2]->getType() == 'v') {
                        upright = true;
                        uprightC[numUpright]= j - j2;
                        numUpright++;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j-j2]->getType() == 'b') {
                        unstable = true;
                        theBoard[i][j-j2]->setType('_');
                    }
                    else if (theBoard[i][j-j2]->getType() == 'h') {
                        if (lateral==false) {
                            lateral = true;
                            lateralR[numLateral] = i;
                            numLateral++;
                        }
                        theBoard[i][j-j2]->setType('_');
                    }
                }
                theBoard[i][j]->setType('b'); // set to unstable square
                theBoard[i+1][j]->setColour(6);
                theBoard[i+2][j]->setColour(6);
                theBoard[i][j-1]->setColour(6);
                theBoard[i][j-2]->setColour(6);
                //theBoard[i][j]->setColour(6);
                if (psychedelic == true) {// if psychedelic square was involved in the match
                    // set all squares in the board of same color to '-' type
                    for (int i2=0; i2 < 10; i2++) {
                        for (int j2=0; j2 < 10; j2++) {
                            if (theBoard[i2][j2]->getColour() == color1) {
                                theBoard[i2][j2]->setColour(6);
                            }
                        }
                    }
                    psychedelic = false;
                }
                if (upright == true) {
				for (int y=0; y<numUpright; y++) {
					int col = uprightC[numUpright];
                    for (int j3 = 0; j3 < 10; j3++) { // set the entire column to type '-'
                        theBoard[j3][col]->setColour(6);
                    }
                    upright = false;
                }
                if (lateral == true) {
                    for (int n = 0; n< numLateral; n++) {
                        int row = lateralR[n];
                            for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
                                theBoard[row][i3]->setColour(6);
                                theBoard[row][i3]->setType('_');
                            }
                    }
                lateral = false;
                }
            }
        }
    }
}
}

Board::~Board(){
	clearBoard();
// delete theBoard;
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


void Board::updateBoard() {
	int numEmpty = 0;
numGenerated = 0;
leftoverLen=leftover.length();
	for (int j = 0; j<10; j++) {
		for (int i=9;i!=-1; i--) {
				if(theBoard[i][j]->getColour() == 6) {
					for (int incr=1; i-incr >=0; incr++) {
						if (theBoard[i-incr][j]->getColour() != 6) {
							theBoard[i][j]->setType(theBoard[i-incr][j]->getType());
							theBoard[i][j]->setColour(theBoard[i-incr][j]->getColour());
							theBoard[i-incr][j]->setColour(6);
							theBoard[i-incr][j]->setType('_');
							break;
						}
					}
				}
			}
numEmpty =0;
		
	}
	for (int j2 = 0; j2<10; j2++) {
		for (int i2=9; i2!=-1; i2--) {
			if (theBoard[i2][j2]->getColour() == 6) {
				int c;
				if (numGenerated < leftoverLen) {
					c= leftover[numGenerated] - 48;
				}
				else {
					numGenerated=0;
					c=leftover[numGenerated];
				}
				numGenerated++;
				theBoard[i2][j2]->changeSquare(c, '_');
			}
		}
}
}
    
int main(){
    ifstream f1("sequence.txt");
    string s;
    //f1 >> s;
    //cout << s << endl;
    Board b(f1);
    cout << b << endl;
    cout << "there you go" << endl;
//  delete b;
   // return 0;
    b.hint();
    b.swap(0,0,'e');
    cout << b << endl;
    cout << "checkMatch on b is " << b.checkMatch() <<endl;   

    b.swap(3,0,'s');
    cout << "swapped square at row 3, column 0 south." << endl;
    cout << b << endl;

    cout << "Next board is after check5Row() and check5Column is called" <<endl;

    b.check5Row();
    b.check5Column();
    cout << b << endl;

	cout <<"We will now updateBoard() : " <<endl;
	b.updateBoard();
	cout << b << endl;

	cout << "leftover is " << b.getLeftover() <<endl;
}

