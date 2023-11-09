#ifndef QUEUE2_H
#define QUEUE2_H
#include "node.h"

template <typename T>
class queue2 {
  private:
    node<T> *tail;
  public:
    queue2() {tail = nullptr;}
    ~queue2();
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
};

template <typename T>
void queue2<T>::push(T dato) {
    node<T> *nodo;
    nodo = new node<T>(dato);
    if (isEmpty()){
        nodo->setNext(nodo);
    }
    else {
        nodo->setNext(tail->getNext());
        tail->setNext(nodo);
    }
    tail = nodo;
}


template <typename T>
queue2<T>::~queue2() {
    while (!isEmpty()){
        pop();
    }
}

template <typename T>
void queue2<T>::pop(){
    if (isEmpty())
        return;

    node<T> *first = tail->getNext();
    if (tail == first) {
        tail = nullptr;
    }
    else {
        node<T> *second = first->getNext();
        tail->setNext(second);
    }
    delete first;
}
template <typename T>
T queue2<T>::front(){
    node<T> *first = tail->getNext();
    return first->getData();
}

template <typename T>
bool queue2<T>::isEmpty() {
    return tail == nullptr;
}
template <typename T>
bool queue2<T>::isFull() {
    return false;
}
#endif