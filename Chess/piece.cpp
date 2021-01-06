#include<iostream>
#include"pieces.h"
#include"list.h"


Piece::Piece(std::string n, int x, int y, bool iW) {

    name = n;
    pos.posX = x;
    pos.posY = y;
    is_white = iW;

}

Pawn::Pawn(int x, int y, bool iW) : Piece("pawn", x, y, iW) {
    firstMove = true;

}

Position * Pawn::move() {

    List<Position> moves;
    Position posi;
    // white is at the bottom of the board
    if (this->is_white) {

        if (firstMove) {
            posi.posX = this->pos.posX;
            posi.posY = this->pos.posY - 2;
            moves.add(posi);
        }

        posi.posX = this->pos.posX;
        posi.posY = this->pos.posY - 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);

        posi.posX = this->pos.posX + 1;
        posi.posY = this->pos.posY - 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);

        posi.posX = this->pos.posX - 1;
        posi.posY = this->pos.posY - 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);

    } else {

        if (firstMove) {
            posi.posX = this->pos.posX;
            posi.posY = this->pos.posY + 2;
            moves.add(posi);
        }

        posi.posX = this->pos.posX;
        posi.posY = this->pos.posY + 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);

        posi.posX = this->pos.posX + 1;
        posi.posY = this->pos.posY + 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);

        posi.posX = this->pos.posX - 1;
        posi.posY = this->pos.posY + 1;
        if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
            moves.add(posi);
    }

    return moves.toArray();

}

Rook::Rook(int x, int y, bool iW) : Piece("rook", x, y, iW) {

}

Position * Rook::move() {

    // moves in straight lines

    List<Position> moves;
    Position posi;

    for (int i = 0; i < 8; i++) {

        if (i != this->pos.posX) {
            posi.posX = i;
            posi.posY = this->pos.posY;
            moves.add(posi);
        }
    }

    for (int i = 0; i < 8; i++) {

        if (i != this->pos.posY) {
            posi.posY = i;
            posi.posX = this->pos.posX;
            moves.add(posi);
        }
    }

    return moves.toArray();

}

Knight::Knight(int x, int y, bool iW) : Piece("knight", x, y, iW) {

}

Position * Knight::move() {

    // moves in L shape

    List<Position> moves;
    Position posi;

    posi.posX = this->pos.posX + 1;
    posi.posY = this->pos.posX + 2;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX - 1;
    posi.posY = this->pos.posX + 2;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX + 2;
    posi.posY = this->pos.posX + 1;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX - 2;
    posi.posY = this->pos.posX + 1;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX + 2;
    posi.posY = this->pos.posX - 1;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX - 2;
    posi.posY = this->pos.posX - 1;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX - 1;
    posi.posY = this->pos.posX - 2;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX = this->pos.posX + 1;
    posi.posY = this->pos.posX - 2;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    return moves.toArray();

}

Bishop::Bishop(int x, int y, bool iW) : Piece("bishop", x, y, iW) {

}

Position * Bishop::move() {

    //moves in diagonals

    List<Position> moves;
    Position posi;

    for (int i = 0; i < 8; i++) {

        if (this->pos.posX + i < 8) {

            if (this->pos.posY + i < 8) {
                posi.posX = this->pos.posX + i;
                posi.posY = this->pos.posY + i;
                moves.add(posi);
            }

            if (this->pos.posY - i >= 0) {
                posi.posX = this->pos.posX + i;
                posi.posY = this->pos.posY - i;
                moves.add(posi);
            }
        }

        if (this->pos.posX - i >= 0) {

            if (this->pos.posY + i < 8) {
                posi.posX = this->pos.posX - i;
                posi.posY = this->pos.posY + i;
                moves.add(posi);
            }

            if (this->pos.posY - i >= 0) {
                posi.posX = this->pos.posX - i;
                posi.posY = this->pos.posY - i;
                moves.add(posi);
            }
        }
    }

    return moves.toArray();

}

Queen::Queen(int x, int y, bool iW) : Piece("queen", x, y, iW) {

}

Position * Queen::move() {

    // moves in diagonals and straight lines

    List<Position> moves;
    Position posi;

    for (int i = 0; i < 8; i++) {
        if (this->pos.posX + i < 8) {
            if (this->pos.posY + i < 8) {
                posi.posX = this->pos.posX + i;
                posi.posY = this->pos.posY + i;
                moves.add(posi);
            }
            if (this->pos.posY - i >= 0) {
                posi.posX = this->pos.posX + i;
                posi.posY = this->pos.posY - i;
                moves.add(posi);
            }
        }
        if (this->pos.posX - i >= 0) {
            if (this->pos.posY + i < 8) {
                posi.posX = this->pos.posX - i;
                posi.posY = this->pos.posY + i;
                moves.add(posi);
            }
            if (this->pos.posY - i >= 0) {
                posi.posX = this->pos.posX - i;
                posi.posY = this->pos.posY - i;
                moves.add(posi);
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (i != this->pos.posX) {
            posi.posX = i;
            posi.posY = this->pos.posY;
            moves.add(posi);
        }
    }

    for (int i = 0; i < 8; i++) {
        if (i != this->pos.posY) {
            posi.posY = i;
            posi.posX = this->pos.posX;
            moves.add(posi);
        }
    }
     

    return moves.toArray();

}


King::King(int x, int y, bool iW) : Piece("queen", x, y, iW) {

}

Position * King::move() {

    List<Position> moves;
    Position posi;

    // top row movement
    posi.posY = this->pos.posY + 1;
    posi.posX = this->pos.posX - 1;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX++;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX++;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    //same row movement
    posi.posY--;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);
    posi.posX -= 2;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    // bottom row movement
    posi.posY--;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX++;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    posi.posX++;
    if (posi.posY < 8 && posi.posY >= 0 && posi.posX < 8 && posi.posX >= 0)
        moves.add(posi);

    return moves.toArray();
}