//engima.h

#ifndef __enigma_h__
#define __enigma_h__

#include<iostream>
#include<fstream>
#include<string>

struct Plug {

    char endA;
    char endB;

};

class PlugBoard {

    private: 

        Plug plugA;
        Plug plugB;

    public:

        PlugBoard(char a, char b, char c, char d);
        PlugBoard();
        char pass(char in);

};

class Rotor {

    private: 

        char scrambler[26];
        int scramblerPos;
        int rotorPos;
        std::string name;

    public:
        
        Rotor(std::string filename, int rotorPos, std::string name);
        Rotor();
        ~Rotor();
        std::string getName();
        void rotate();
        bool hasRotated();
        char getNodePos();
        void setNodePos(char newPos);
        int getRotorPos();
        char encrypt(char in);

};

class Enigma {

    private:

        Rotor* rotorA;
        Rotor* rotorB;
        Rotor* rotorC;
        PlugBoard* plugBoard;

    public:

        Enigma(int rotor1, int rotor2, int rotor3, 
               int scramblerPos1, int scramblerPos2, int scramblerPos3,
               char pb1, char pb2, char pb3, char pb4);
        Enigma();
        ~Enigma();
        std::string getFilename(int rotor);
        std::string getRomanNumeral(int number);
        void setRotor(int oldRotorPos, int newRotor, int scramblerPos);
        void setPlugBoard(char pb1, char pb2, char pb3, char pb4);
        std::string getRotorName(int rotorPos);
        char encrypt(char in);
};

#endif