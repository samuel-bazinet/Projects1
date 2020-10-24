// CCdll.h

#ifndef __CCdll_h__
#define __CCdll_h__

#include<string>

struct Node {
    Node *next;
    Node *prev;
    char chr;
    int count;
};

class DoubLinLis {

    private:

        Node *head;

    public:

        DoubLinLis();
        ~DoubLinLis();
        void count(char el);
        bool compare(Node *c1, Node *c2);
        void move(Node *el);
        std::string toString();

};

#endif