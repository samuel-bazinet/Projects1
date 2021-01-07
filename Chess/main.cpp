#include<iostream>
#include"pieces.h"

typedef Piece** PieceArr2;
typedef Piece* PieceArr;

using namespace std;


int main() {


    PieceArr2* board = new PieceArr2[8];
    for (int i = 0; i < 8; i++) {
        board[i] = new PieceArr[8];
    }

    for (int i = 0; i < 8; i++) {
        Pawn newPawn(i, 1, false);
        board[i][1] = &newPawn;
        Pawn newPawn2(i, 6, true);
        board[i][6] = &newPawn2;
    }

    Rook newRook(0, 0, false);
    board[0][0] = &newRook;
    Rook newRook2(0, 7, false);
    board[0][7] = &newRook2;
    Rook newRook3(7, 0, true);
    board[7][0] = &newRook3;
    Rook newRook4(7, 7, true);
    board[7][7] = &newRook4;

    Knight newKnight(1,0, false);
    board[1][0] = &newKnight;
    Knight newKnight(6,0, false);
    board[6][0] = &newKnight;
    Knight newKnight(1,7, true);
    board[1][7] = &newKnight;
    Knight newKnight(6,7, true);
    board[6][7] = &newKnight;

    Bishop newBishop(2, 0, false);
    board[2][0] = &newBishop;


    return 0;
}