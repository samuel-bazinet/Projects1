// pieces.h

#ifndef __pieces_h__
#define __pieces_h__

#include"piece.h"

class Pawn: private virtual Piece {

    public:

        Pawn(std::string n, int x, int y, bool iW);
        Position * move();

};

class Rook: private virtual Piece {

    public:

        Rook(std::string n, int x, int y, bool iW);
        Position * move();

};

class Knight: private virtual Piece {

    public:

        Knight(std::string n, int x, int y, bool iW);
        Position * move();

};

class Bishop: private virtual Piece {

    public:

        Bishop(std::string n, int x, int y, bool iW);
        Position * move();

};

class Queen: private virtual Piece {

    public:

        Queen(std::string n, int x, int y, bool iW);
        Position * move();

};

class King: private virtual Piece {

    public:

        King(std::string n, int x, int y, bool iW);
        Position * move();

};



#endif 