#include <iostream>
#include <string>
#include "square.h"

using namespace std;

Square::Square():colour(0),type('_'),special('_'),x(0),y(0){}
Square::Square(int x, int y, int c, char t, char s):x(x),y(y),colour(c),type(t),special(s){}
	//void mutatesquare(int x, int y, int c, char t=0, char s=0);
int Square::getColour(){
	return colour;
}

void Square::changeSquare(int colour, char type) {
	this->colour = colour;
	this->type = type;
}

void Square::setColour(int colour) {
	colour(colour);
}

char Square::getType(){
	return type;
}
char Square::getSpecial(){
	return special;
}
int Square::getX(){
	return x;
}
int Square::getY(){
	return y;
}
//void Square::setDisplay(textDisplay &td){}
//	void setPos(int x, int y); 
//	virtual bool checkMatch();
//	virtual void notify(int x, int y, char d); 

ostream& operator<<(ostream &out, Square &sq){
	out << sq.special << sq.type << sq.colour;
	return out;
}

//	~Square()=0;
