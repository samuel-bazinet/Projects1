// piece.h

#ifndef __piece_h__
#define __piece_h__

#include<string>

struct Position {

    int posX;
    int posY;

};

class Piece {

    protected:

        std::string name;
        Position pos;
        bool is_white;
    
    public:

        Piece();
        Piece(std::string n, int x, int y, bool iW);
        virtual Position * move() = 0;

};


#endif