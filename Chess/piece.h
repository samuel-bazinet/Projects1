// piece.h

#ifndef __piece_h__
#define __piece_h__

#include<string>

class Piece {

    private:

        std::string name;
        int posX;
        int posY;
    
    public:

        Piece();
        void Move(int x, int y);



};


#endif