// pieces.h

#ifndef __pieces_h__
#define __pieces_h__

#include<string>
#include"piece.h"

class Pawn: private Piece {

    public:

        Pawn(std::string n, int x, int y, bool iW);

};

class Rook: private Piece {

    public:

        Rook(std::string n, int x, int y, bool iW);

};

class Knight: private Piece {

    public:

        Knight(std::string n, int x, int y, bool iW);

};

class Bishop: private Piece {

    public:

        Bishop(std::string n, int x, int y, bool iW);

};

class Queen: private Piece {

    public:

        Queen(std::string n, int x, int y, bool iW);

};

class King: private Piece {

    public:

        King(std::string n, int x, int y, bool iW);

};



#endif 