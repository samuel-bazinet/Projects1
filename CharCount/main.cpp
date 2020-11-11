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

    delete hullo;

    return 0;
}