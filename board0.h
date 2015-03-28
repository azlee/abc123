#ifndef __BOARD0_H__
#define __BOARD0_H__
#include <iostream>
#include <string>
#include "Board.h"

class Board0 : public{
    private:
        int numGenerated = 0;
        int leftoverLen;
        std::string leftover;
    public:
        Board0();
        void fillBoard(int l);
        ~Board0();
};

#endif
