// pieces.h

#ifndef __pieces_h__
#define __pieces_h__

#include<iostream>
#include"piece.h"
#include"list.h"

class Pawn: public virtual Piece {

    public:

        bool firstMove;
        Pawn(int x, int y, bool iW);
        Position * move();

};

class Rook: public virtual Piece {

    public:

        Rook(int x, int y, bool iW);
        Position * move();

};

class Knight: public virtual Piece {

    public:

        Knight(int x, int y, bool iW);
        Position * move();

};

class Bishop: public virtual Piece {

    public:

        Bishop(int x, int y, bool iW);
        Position * move();

};

class Queen: public virtual Piece {

    public:

        Queen(int x, int y, bool iW);
        Position * move();

};

class King: public virtual Piece {

    public:

        King(int x, int y, bool iW);
        Position * move();

};



#endif 