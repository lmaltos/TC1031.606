#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>

template <class T>
class LinkedList {
    private:
    node<T> *head;
    int size;
    node<T>* getByPos(int);
  public:
    LinkedList() {
        head = NULL;
        size = 0;
    }
    ~LinkedList();
    void addFist(T);
    void addLast(T);
    T operator[](int);
    void print();
};

template <class T>
void deleteRecursivo(node<T>* nodo) {
    if (nodo->getNext() != NULL)
        deleteRecursivo(nodo->getNext());
    std::cout << nodo << "\t" << nodo->getData() << std::endl;
    delete nodo;
}

template <class T>
LinkedList<T>::~LinkedList() {
    node<T> *nodo,*next;
    //deleteRecursivo(head);
    nodo = head;
    while (nodo != NULL) {
        next = nodo->getNext();
        std::cout << nodo << "\t" << nodo->getData() << std::endl;
        delete nodo;
        nodo = next;
    }
}

template <class T>
void LinkedList<T>::addFist(T data) {
    node<T>* nuevoNodo;
    nuevoNodo = new node<T>(data,head);
    head = nuevoNodo;
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    node<T>* nuevoNodo, *last;
    nuevoNodo = new node<T>(data,NULL);
    if (head != NULL) {
        last = head;
        while (last->getNext() != NULL) {
            last = last->getNext();
        }
        last->setNext(nuevoNodo);
    }
    else {
        head = nuevoNodo;
    }
    size++;
}

template <class T>
node<T>* LinkedList<T>::getByPos(int k) {
    node<T> *nodo;
    if (k < 0 || k > size)
        throw std::out_of_range("k pos out of range");
    nodo = head;
    for (int i = 0;i < k;i++) {
        nodo = nodo->getNext();
    }
    return nodo;
}

template <class T>
T LinkedList<T>::operator[](int k) {
    node<T> *nodo = getByPos(k);
    return nodo->getData();
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