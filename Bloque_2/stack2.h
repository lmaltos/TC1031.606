#ifndef STACK2_H
#define STACK2_H
#include "node.h"

template <typename T>
class stack2 {
  private:
    node<T> *top;
  public:
    stack2();
    ~stack2();
    void push(T);
    T Top();
    void pop();
    bool isFull();
    bool isEmpty();
};

template <typename T>
stack2<T>::stack2() {
    top = NULL;
}

template <typename T>
void stack2<T>::push(T dato) {
    node<T> *newNode;
    newNode = new node<T>(dato,top);
    top = newNode;
}

template <typename T>
T stack2<T>::Top() {
    return top->getData();
}

template <typename T>
void stack2<T>::pop() {
    node<T> *nodo;
    nodo = top;
    top = top->getNext();
    delete nodo;
}

template <typename T>
bool stack2<T>::isFull() {
    return false;
}

template <typename T>
bool stack2<T>::isEmpty() {
    return top == NULL;
}

#endif