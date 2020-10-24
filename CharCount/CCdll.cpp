#include<iostream>
#include<string>
#include"CCdll.h"

using namespace std;

DoubLinLis::DoubLinLis() {

    Node *current;
    current->prev = NULL;
    current->chr = char(0);
    current->count = 0;
    current->next = NULL;
    head = current;

    for (int i = 1; i < 128; i++) {
        Node *newNode = new Node;
        newNode->prev = current;
        newNode->next = NULL;
        newNode->chr = char(i);
        newNode->count = 0;
        current->next = newNode;

        current = newNode;
    }

}

DoubLinLis::~DoubLinLis() {
    Node *ToDel = head->next;

    while(ToDel->next != NULL) {
        cout << "hey" << endl;
        delete ToDel->prev;
        ToDel = ToDel->next;
    }

    delete ToDel;
    cout << "hullo" << endl;

}


void DoubLinLis::count(char el) {
    Node *current = head;
    while(current->chr != el && current->next != NULL) {
        current = current->next;
    }

    if (current->next == NULL) {
        return;
    }

    current->count++;

    if (compare(current, current->prev)) {
        //cout << "go" << endl;
        move(current);
    }

}

bool DoubLinLis::compare(Node *c1, Node *c2) {
    if (c2 == NULL) {
        return false;    
    }
    //cout << c1->chr << " " << c2->chr << endl;
    //cout << c1->count << " " << c2->count << endl;

    if (c2->count == 0) 
        return true;
    
    return (c1->count > c2->count);
}

void DoubLinLis::move(Node *el) {
    if (el->prev->chr == head->chr) {
        el->prev->next = el->next;
        el->prev->prev = el;
        el->next = el->prev;
        el->prev = NULL;
        head = el;
        return;
    }

    el->prev->prev->next = el;
    el->prev->next = el->next;
    el->next->prev = el->prev;
    el->next = el->prev;
    el->prev = el->prev->prev;
    el->next->prev = el;
 

    if (compare(el, el->prev)) {
        //std::cout << "again" << std::endl;
        move(el);
    }  
}

std::string DoubLinLis::toString() {
    std::string out;
    Node *current = head;

    while(current->next != NULL) {
        if (current->count == 0) {
            current = current->next;
            continue;
        }
        out += "\"";
        out += current->chr;
        out += "\": ";
        out += to_string(current->count);
        out += "\n";
        current = current->next;
    }

    if (current->count != 0) {
        out += current->chr;
        out += ": ";
        out += current->count;
        out += "\n";
    }

    return out;

}


