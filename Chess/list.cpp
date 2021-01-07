#include<iostream>
#include"list.h"

template <class T>
List<T>::List() {
    head->next = NULL;
    head->el = NULL;
}

template <class T>
List<T>::~List() {
    Node<T> toDel = head;
    Node<T> current;
    while (size > 1) {
        current = toDel->next;
        delete toDel;
        size--;
        toDel = current;
    }
    delete toDel;
    delete current;
    size = 0;
}

template <class T>
bool List<T>::isEmpty() {
    return (size == 0);
}

template <class T>
void List<T>::add(T el) {
    Node<T> newEl;
    newEl->el = el;
    newEl->next = NULL;
    if (head->el == NULL) {
        head = newEl;
        size++;
        return;
    }

    Node<T> current = head;
    while (current->next != NULL) {
        current = current->next;
    }   
    current->next = newEl;
    size++;
}

template <class T>
T* List<T>::toArray() {

    T *outArr = new T[size];
    Node<T> current = head;

    for (int i = 0; i < size; i++) {
        outArr[i] = current;
        current = current->next;
    }

    return outArr;

}