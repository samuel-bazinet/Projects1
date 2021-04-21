#include"enigma.h"

/**
 * This is the constructor for the PlugBoard class
 * @param a End A of plug A
 * @param b End B of plug A
 * @param c End A of plug B
 * @param d End B of plug B
 */
PlugBoard::PlugBoard(char a, char b, char c, char d) {

    plugA.endA = a;
    plugA.endB = b;
    plugB.endA = c;
    plugB.endB = d;

}

/**
 * pass takes a character and passes it through the plugboard, converting it in necessary.
 * @param in The character passing through the plugBoard 
 * @return The charater connected to the input if there is a plug, otherwise, it returns in.
*/
char PlugBoard::pass(char in) {

    if (in == plugA.endA) {

        return plugA.endB;
    
    } else if (in == plugA.endB) {

        return plugA.endA;

    } else if (in == plugB.endA) {

        return plugB.endB;

    } else if (in == plugB.endB) {

        return plugB.endA;

    } else  {

        return in;

    }

}

/**
 * Construtor for Rotor class
 * @param filename The file containing the order of the scrambler
 * @param rotorPos The position of the rotor on the machine (1-3)
 * @param name The name of the rotor
*/
Rotor::Rotor(std::string filename, int rotorPos, std::string name) {

    scramblerPos = 0;
    this->rotorPos = rotorPos;
    this->name = name;

    std::ifstream fin (filename);

    std::string line;

    for (int i = 0; i < 26; i++) {

        fin >> line; 
        this->scrambler[i] = line.at(0);

    }

    fin.close();

}

/**
 * Destructor for Rotor class
 */
Rotor::~Rotor() {

    std::cout << "Deleted " << this->name << std::endl;

}

/**
 * getName returns the name of the rotor.
 * @return The name of the rotor
 */
std::string Rotor::getName() {return this->name; }

/**
 * rotate rotates the rotor. 
 */
void Rotor::rotate() {this->scramblerPos++; }

/**
 * hasRotated returns whether or not the rotor has completed a revolution
 * @return Whether or not it has rotated.
 */
bool Rotor::hasRotated() {

    if (this->scramblerPos == 26) {

        this->scramblerPos = 0;
        return true; 

    } else {

        return false;
    
    }

}

/**
 * getNodePos returns the position of the node
 * @return The position of the node
 */
char Rotor::getNodePos() {return char('A' + this->scramblerPos); }

/**
 * setNodePos changes the position of the scrambler
 * @param newPos The new position of the scrambler
 */
void Rotor::setNodePos(char newPos) {

    scramblerPos = (newPos - 'A');

}

/**
 * getRotorPos returns the position of the rotor on the machine
 * @return The position of the rotor on the machine
 */
int Rotor::getRotorPos() {return this->rotorPos; }

/**
 * encrypt takes a character, and passes it through the rotor
 * @param in The character to be passed through the rotor
 * @return The character after being encrypted
 */
char Rotor::encrypt(char in) {

    return scrambler[((in -'A') + scramblerPos) % 26];

}

/**
 * This is the constructor for the Enigma class
 * @param rotor1 The Rotor to use in pos 1
 * @param rotor2 The rotor to use in pos 2
 * @param rotor3 The rotor to use in pos 3
 * @param scramblerPos1 The scrambler position for rotor 1
 * @param scramblerPos2 The scrambler position for rotor 2
 * @param scramblerPos3 The scrambler position for rotor 3
 * @param pb1 End A of Plug A
 * @param pb2 End B of Plug A
 * @param pb3 End A of Plug B
 * @param pb4 End B of Plus B
 */ 
Enigma::Enigma(int rotor1, int rotor2, int rotor3, 
               int scramblerPos1, int scramblerPos2, int scramblerPos3,
               char pb1, char pb2, char pb3, char pb4) {

    rotorA = new Rotor(this->getFilename(rotor1), 1, this->getRomanNumeral(rotor1));
    rotorB = new Rotor(this->getFilename(rotor2), 2, this->getRomanNumeral(rotor2));
    rotorC = new Rotor(this->getFilename(rotor3), 3, this->getRomanNumeral(rotor3));

    rotorA->setNodePos(scramblerPos1);
    rotorB->setNodePos(scramblerPos2);
    rotorC->setNodePos(scramblerPos3);

    plugBoard = new PlugBoard(pb1, pb2, pb3, pb4);

}

Enigma::~Enigma() {

}

/**
 * getFilename get the name of the file containing the corresponding settings for the rotor
 * @param rotor The number of the file containing the settings
 * @return The name of the file containing the settings
 */
std::string Enigma::getFilename(int rotor) {

    switch(rotor) {

        case 1:

            return "RotorI.txt";

        case 2:

            return "RotorII.txt";

        case 3:

            return "RotorIII.txt";

        case 4:

            return "RotorIV.txt";

        case 5:

            return "RotorV.txt";

        case 6:

            return "RotorVI.txt";

        case 7:

            return "RotorVII.txt";

        case 8:

            return "RotorVIII.txt";

        default:
            
            std::cerr << "Inputted invalid number, using rotor 1" << std::endl;
            return "RotorI.txt";

    }

}

/**
* getRomanNumeral converts a number into its roman numeral equivalent
* @param number the number to convert
* @return The Roman numeral
*/
std::string Enigma::getRomanNumeral(int number) {

    switch(number) {

        case 1:

            return "I";

        case 2:

            return "II";

        case 3:

            return "III";

        case 4:

            return "IVt";

        case 5:

            return "V";

        case 6:

            return "VI";

        case 7:

            return "VII";

        case 8:

            return "VIII";

        default:
            
            std::cerr << "Inputted invalid number, using I" << std::endl;
            return "I";

    }

}

/**
 * setRotor changes a rotor on the enigma machine
 * @param oldRotorPos The position of the rotor to change
 * @param newRotor The rotor to replace the old one
 * @param scramblerPos The position of the new scrambler
 */
void Enigma::setRotor(int oldRotorPos, int newRotor, int scramblerPos) {

    if (oldRotorPos == 1) {

        delete rotorA;
        rotorA = new Rotor(this->getFilename(newRotor), 1, this->getRomanNumeral(newRotor));
        rotorA->setNodePos(scramblerPos);

    } else if (oldRotorPos == 2) {

        delete rotorB;
        rotorB = new Rotor(this->getFilename(newRotor), 2, this->getRomanNumeral(newRotor));
        rotorB->setNodePos(scramblerPos);

    } else {

        delete rotorC;
        rotorC = new Rotor(this->getFilename(newRotor), 1, this->getRomanNumeral(newRotor));
        rotorC->setNodePos(scramblerPos);
        
    }

}

/**
 * setPlugBoard replaces the settings on the plugBoard
 * @param pb1 End A of Plug A
 * @param pb2 End B of Plug A
 * @param pb3 End A of Plug B
 * @param pb4 End B of Plus B
 */
void Enigma::setPlugBoard(char pb1, char pb2, char pb3, char pb4) {

    delete plugBoard;
    plugBoard = new PlugBoard(pb1, pb2, pb3, pb4);

}

/**
 * getRotorName returns the name of the rotor
 * @param rotorPos The position of the rotor to get the name from
 * @return The name of the rotor
 */
std::string Enigma::getRotorName(int rotorPos) { 

    if (rotorPos == 1) {

        return rotorA->getName();

    } else if (rotorPos == 2) {

        return rotorB->getName();

    } else {

        return rotorC->getName();
        
    }

} 

/**
 * encrypt encrypts a char into another one
 * @param in The char inputted
 * @return The encrypted char
 */
char Enigma::encrypt(char in) {

    if (in < 'A' || in > 'Z') {
        return in;
    }

    //std::cout << "Encrypting: " << in << std::endl;

    // We make the input go throught the plugboard
    char out = plugBoard->pass(in);

    //std::cout << "Rotors " << out  << std::endl;

    // We then go through the rotors
    out = rotorA->encrypt(out);
    out = rotorB->encrypt(out);
    out = rotorC->encrypt(out);

    //std::cout << "Reflector " << out << std::endl;
    // The we hit the reflector and got the other way
    out = rotorC->encrypt(out);
    out = rotorB->encrypt(out);
    out = rotorA->encrypt(out);

    //std::cout << "Plug " << out << std::endl;
    // We go through the plugboard on the way out
    out = plugBoard->pass(out);

    // We rotate the first rotor
    rotorA->rotate();

    // if a rotor moves, we check to see if we increment the next one
    if (rotorA->hasRotated()) {

        rotorB->rotate();

        if (rotorB->hasRotated()) {

            rotorC->rotate();

        }

    }

    return out;

}