#include"enigma.h"

using namespace std;

int main() {

    Enigma machine = Enigma(1, 2, 3, 'A', 'A', 'A', 'A', 'Z', 'G', 'T');

    string input;

    while (true) {

        cin >> input;
        if (input.at(0) == ';') {
            break;
        }

        for (int i = 0; i < input.length(); i++) {
            cout << machine.encrypt(input.at(i));
        }

        cout << endl;

    }

    cout << "Goodbye" << endl;

}