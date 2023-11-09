#ifndef AVL_H
#define AVL_H
#include "BST.h"
#include "stack2.h"
#include <iostream>

class AVL : public BST {
  private:
    bool isBalanced(int,nodeT*);
    nodeT* getPivote(int);
    void RSI(nodeT*,int);
    void RSD(nodeT*,int);
    void RDI(nodeT*,int);
    void RDD(nodeT*,int);
    void cambiarPivote(nodeT*,nodeT*);
    nodeT* getPadre(nodeT*);
  public:
    void push(int);
    bool isBalanced(int);
    int calcAltura(nodeT*);
};

void AVL::push(int n) {
    std::cout << "Entra a push valor " << n << std::endl;
    BST::push(n); // agrega nodo como se haría en un BST
    if (!isBalanced(n)) { // no esta balanceado 
        std::cout << "No esta balanceado" << std::endl;
        // encontrar el pivote
        nodeT *pivote = getPivote(n);
        nodeT *A;
        // tipo de rotacion a realizar
        if (pivote->getData() < n) {
            std::cout << "Rotacion a la izquierda ";
            A = pivote->getRight();
            if (A->getData() < n) {
                std::cout << "simple";
                RSI(pivote,n);
            }
            else {
                std::cout << "doble";
                RDI(pivote,n);
            }
        }
        else {
            std::cout << "Rotacion a la derecha ";
            A = pivote->getLeft();
            if (A->getData() > n) {
                std::cout << "simple";
                RSD(pivote,n);
            }
            else {
                std::cout << "doble";
                RDD(pivote,n);
            }
        }
        std::cout << "\tpivote " << pivote->getData() << std::endl;
    }
}

bool AVL::isBalanced(int n, nodeT* nodo) {
    int altLeft = calcAltura(nodo->getLeft());
    int altRight = calcAltura(nodo->getRight());
    if (altRight - altLeft > 1 || altRight - altLeft < -1)
        return false;
    nodeT* next;
    if (n < nodo->getData())
        next = nodo->getLeft();
    else if (n > nodo->getData()){
        next = nodo->getRight();
    }
    else {
        return true; // se ha llegado al nodo hoja, el arbol esta balanceado
    }
    return isBalanced(n,next);
}

bool AVL::isBalanced(int n) {
    return isBalanced(n, root);
}

int AVL::calcAltura(nodeT* nodo){
    if (nodo == NULL)
        return 0;
    int altLeft = calcAltura(nodo->getLeft());
    int altRight = calcAltura(nodo->getRight());
    return (altLeft > altRight ? altLeft : altRight) + 1;
}

nodeT* AVL::getPivote(int n){
    nodeT *pivote;
    nodeT *nodo = root;
    while (nodo->getData() != n) {
        if (!isBalanced(n,nodo)) {
            pivote = nodo;
        }
        nodo = nodo->getData() > n ? nodo->getLeft() : nodo->getRight();
    }
    return pivote;
}

void AVL::RSI(nodeT* pivote, int data) {
    nodeT *A = pivote->getRight();
    pivote->setRight(A->getLeft());
    A->setLeft(pivote);
    cambiarPivote(pivote,A);
}

void AVL::RSD(nodeT* pivote, int data) {
    nodeT *A = pivote->getLeft();
    pivote->setLeft(A->getRight());
    A->setRight(pivote);
    cambiarPivote(pivote,A);
}

void AVL::RDI(nodeT* pivote, int data) {
    // ToDo
}

void AVL::RDD(nodeT* pivote, int data) {
    // ToDo
}

void AVL::cambiarPivote(nodeT *B, nodeT *A) {
    // Quien apuntaba a B, ahora apuntara a A
    if (B == root) {
        root = A;
        return;
    }
    nodeT *padre = getPadre(B);
    if (padre->getData() > B->getData())
        padre->setLeft(A);
    else
        padre->setRight(A);
}

nodeT* AVL::getPadre(nodeT *B) {
    nodeT *nodo = root;
    nodeT *padre;
    while (nodo != B) {
        padre = nodo;
        nodo = nodo->getData() > B->getData() ? nodo->getLeft() : nodo->getRight();
    }
    return padre;
}

#endif