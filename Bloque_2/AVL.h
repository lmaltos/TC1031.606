#ifndef AVL_H
#define AVL_H
#include "BST.h"
#include "stack2.h"

class AVL : public BST {
  private:
    bool isBalanced(int,nodeT*);
    nodeT* getPivote(int);
  public:
    void push(int);
    bool isBalanced(int);
    int calcAltura(nodeT*);
};

void AVL::push(int n) {
    BST::push(n); // agrega nodo como se haría en un BST
    if (!isBalanced(n)) { // no esta balanceado 
        // encontrar el pivote
        nodeT *pivote = getPivote(n);
        // tipo de rotacion a realizar
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
    stack2<nodeT*> pila;
    nodeT *nodo = root;
    while (nodo->getData() != n) {
        pila.push(nodo);
        nodo = nodo->getData() < n ? nodo->getLeft() : nodo->getRight();
    }
    do {
        nodo = pila.Top();
        pila.pop();
        if (!isBalanced(n,nodo)) {
            return nodo; // nodo mas cercano a la hoja que esta desbalanceado
        }
    } while (!pila.isEmpty());
    return NULL;
}

#endif