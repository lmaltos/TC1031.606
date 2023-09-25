#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>

template <class T>
class LinkedList {
    private:
    node<T> *head;
    int size;
  public:
    LinkedList() {
        head = NULL;
        size = 0;
    }
    ~LinkedList();
    void addFist(T);
    void print();
};

template <class T>
LinkedList<T>::~LinkedList() {

}

template <class T>
void LinkedList<T>::addFist(T data) {
    node<T>* nuevoNodo;
    nuevoNodo = new node<T>(data,head);
    head = nuevoNodo;
}

template <class T>
void LinkedList<T>::print() {
    node<T> *nodo;
    nodo = head;
    while (nodo != NULL) {
        std::cout << nodo->getData() << " ";
        nodo = nodo->getNext();
    }
    std::cout << std::endl;
}
#endif