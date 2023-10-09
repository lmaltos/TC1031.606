#ifndef BST_H
#define BST_H
#include "nodeT.h"

class BST {
  private:
    nodeT *root;
  public:
    BST();
    bool search(int);
    void push(int);
};

BST::BST() {
    root = NULL;
}

bool BST::search(int dato) {
    nodeT *p;
    p = root;
    while (p != NULL) {
        if (p->getData() == dato)
            return true;
        p = p->getData() > dato ? p->getLeft() : p->getRight();
    }
    return false;
}

void BST::push(int dato) {
    if (search(dato))
        return; // el elemento ya se encuentra en el arbol
    nodeT *p,*q = NULL;
    p = root;
    while (p != NULL) {
        q = p;
        p = p->getData() > dato ? p->getLeft() : p->getRight();
    }
    nodeT *nodo;
    nodo = new nodeT(dato);
    if (q != NULL) {
        if (q->getData() > dato) {
            q->setLeft(nodo);
        }
        else {
            q->setRight(nodo);
        }
    }
    else {
        root = nodo;
    }
}

#endif