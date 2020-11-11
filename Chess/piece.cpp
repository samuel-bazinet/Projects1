#include<iostream>
#include"pieces.h"


Piece::Piece(std::string n, int x, int y, bool iW) {

    name = n;
    pos.posX = x;
    pos.posY = y;
    is_white = iW;

}

Pawn::Pawn(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position Pawn::move() {

}

Rook::Rook(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position Rook::move() {

}

Knight::Knight(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position Knight::move() {

}

Bishop::Bishop(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position Bishop::move() {

}

Queen::Queen(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position Queen::move() {

}

King::King(std::string n, int x, int y, bool iW) : Piece(n, x, y, iW) {

}

Position King::move() {
    
}