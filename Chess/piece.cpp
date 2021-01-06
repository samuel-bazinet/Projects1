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
        moves.add(posi);
        posi.posX = this->pos.posX + 1;
        posi.posY = this->pos.posY - 1;
        moves.add(posi);
        posi.posX = this->pos.posX - 1;
        posi.posY = this->pos.posY - 1;
        moves.add(posi);

    } else {
        if (firstMove) {
            posi.posX = this->pos.posX;
            posi.posY = this->pos.posY + 2;
            moves.add(posi);
        }
        posi.posX = this->pos.posX;
        posi.posY = this->pos.posY + 1;
        moves.add(posi);
        posi.posX = this->pos.posX + 1;
        posi.posY = this->pos.posY + 1;
        moves.add(posi);
        posi.posX = this->pos.posX + 1;
        posi.posY = this->pos.posY + 1;
        moves.add(posi);
    }

    return moves.toArray();

}

Rook::Rook(int x, int y, bool iW) : Piece("rook", x, y, iW) {

}

Position * Rook::move() {

}

Knight::Knight(int x, int y, bool iW) : Piece("knight", x, y, iW) {

}

Position * Knight::move() {

}

Bishop::Bishop(int x, int y, bool iW) : Piece("bishop", x, y, iW) {

}

Position * Bishop::move() {

}

Queen::Queen(int x, int y, bool iW) : Piece("queen", x, y, iW) {

}

Position * Queen::move() {

}

King::King(int x, int y, bool iW) : Piece("queen", x, y, iW) {

}

Position * King::move() {
    
}