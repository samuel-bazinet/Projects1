//list.h

#ifndef __list_h__
#define __list_h__

template <class T>
struct Node {
    Node *next;
    T el;
};

template <class G>
class List {
    private:

        Node<G> *head;
        int size;
    
    public:

        List();
        ~List();
        bool isEmpty();
        void add(G);
        int getSize(){return size;}
        G* toArray();
    
};

#endif