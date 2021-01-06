// pieces.h

#ifndef __pieces_h__
#define __pieces_h__

#include"piece.h"

class Pawn: private virtual Piece {

    public:

        bool firstMove;
        Pawn(int x, int y, bool iW);
        Position * move();

};

class Rook: private virtual Piece {

    public:

        Rook(int x, int y, bool iW);
        Position * move();

};

class Knight: private virtual Piece {

    public:

        Knight(int x, int y, bool iW);
        Position * move();

};

class Bishop: private virtual Piece {

    public:

        Bishop(int x, int y, bool iW);
        Position * move();

};

class Queen: private virtual Piece {

    public:

        Queen(int x, int y, bool iW);
        Position * move();

};

class King: private virtual Piece {

    public:

        King(int x, int y, bool iW);
        Position * move();

};



#endif 