#include<iostream>
#include<fstream>
#include<string>
#include"CCdll.h"

using namespace std;

int main() {


    DoubLinLis hullo = DoubLinLis();

    
    std::string test = "I like pie";

    std::cout << "We will test: " << test << std::endl;

    for (char el: test) {
        hullo.count(el);
    }

    std::cout << hullo.toString() << std::endl;
    
    /*
    fstream file;
    file.open("test.txt", ios::in);
    if (file.is_open()) {
        string read;
        while(getline(file, read)) {
            for (char el: read) {
                hullo.count(el);
            }
        }
        file.close();
    }

    std::cout << hullo.toString() << std::endl;
    */
    return 0;
}