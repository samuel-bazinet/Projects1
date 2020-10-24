#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"CCdll.h"

using namespace std;

int main() {


    DoubLinLis *hullo = new DoubLinLis();

    std::string test = "I like pie";

    std::cout << "We will test: " << test << std::endl;

    for (char el: test) {
        hullo->count(el);
    }

    std::cout << hullo->toString() << std::endl;


    //hullo->~DoubLinLis();
    //hullo = new DoubLinLis();
/*    string fileName;

    cout << "hello" << endl;




    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            for(char el: line) {
                hullo.count(el);
            }
        }
        cout << hullo.toString() << endl;
    }
    myfile.close(); 
     

*/

/*
    for (int i = 0; i < 128; i++) {
        std::cout << "\"" << char(i) << "\"" << std::endl;
    }
*/
    return 0;
}