#ifndef BST_H
#define BST_H
#include "nodeT.h"
#include "queue2.h"
#include <iostream>

class BST {
  protected:
    nodeT *root;
  public:
    BST();
    ~BST();
    void borraNodo(nodeT*);
    bool search(int);
    void push(int);
    void pop(int);
    void preorden(nodeT*);
    void printPreorden();
    void inorden(nodeT*);
    void printInorden();
    void postorden(nodeT*);
    void printPostorden();
    void printPorNivel();
    int calcNivel(nodeT*);
};

BST::BST() {
    root = NULL;
}

BST::~BST() {
    borraNodo(root);
}

void BST::borraNodo(nodeT *nodo) {
    if (nodo == NULL)
        return;
    borraNodo(nodo->getLeft());
    borraNodo(nodo->getRight());
    std::cout << "Delete node " << nodo->getData() << std::endl;
    delete nodo;
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

void BST::pop(int dato) {
    if (!search(dato))
        return; // el elemento no se encuentra en el arbol
    nodeT *p,*q = NULL;
    p = root;
    while (p->getData() != dato) {
        q = p; // nodo padre
        p = p->getData() > dato ? p->getLeft() : p->getRight();
    } // regresa el nodo que tiene el dato
    if (p->getLeft() == NULL && p->getRight() == NULL) { // se trata de un nodo hoja
        if (q == NULL) { // es el unico dato en el arbol
            root = NULL; // se vacia el arbol
        }
        else {
            if (q->getData() > dato) {
                q->setLeft(NULL); // el nodo p esta a la izquierda
            }
            else {
                q->setRight(NULL); // el nodo p esta a la derecha porque dato > q->dato
            }
        }
        delete p; // se libera nodo
    }
    else if (p->getLeft() == NULL || p->getRight() == NULL) { // se trata de un nodo con un solo hijo
        nodeT *subarbol;
        subarbol = p->getLeft() != NULL ? p->getLeft() : p->getRight();
        if (q == NULL) { // p == root
            root = subarbol;
        }
        if (q->getData() > dato) {
            q->setLeft(subarbol); // el nodo p esta a la izquierda
        }
        else {
            q->setRight(subarbol); // el nodo p esta a la derecha porque dato > q->dato
        }
        delete p; // se libera nodo
    }
    else { // se trata de un nodo con dos hijos
        nodeT *predecesor;
        predecesor = p->getLeft();
        q = p;
        while (predecesor->getRight() != NULL) {
            q = predecesor;
            predecesor = predecesor->getRight();
        }
        nodeT *subarbol = predecesor->getLeft();
        p->setData(predecesor->getData()); // actualizamos informacion en nodo p
        delete predecesor; // se libera nodo predecesor
        if (q == p) {
            q->setLeft(subarbol);
        }
        else {
            q->setRight(subarbol);
        }
    }
}

void BST::preorden(nodeT* nodo) {
    if (nodo == NULL)
        return;
    std::cout << nodo->getData() << " ";
    preorden(nodo->getLeft());
    preorden(nodo->getRight());
}

void BST::printPreorden(){
    preorden(root);
}

void BST::inorden(nodeT* nodo){
    if (nodo == NULL)
        return;
    inorden(nodo->getLeft());
    std::cout << nodo->getData() << " ";
    inorden(nodo->getRight());
}

void BST::printInorden(){
    inorden(root);
}

void BST::postorden(nodeT* nodo){
    if (nodo == NULL)
        return;
    postorden(nodo->getLeft());
    postorden(nodo->getRight());
    std::cout << nodo->getData() << " ";
}

void BST::printPostorden(){
    postorden(root);
}


void BST::printPorNivel() {
    queue2<nodeT*> fila;
    nodeT *nodo;
    int nivelActual = 0;
    fila.push(root);
    while (!fila.isEmpty()) {
        nodo = fila.front();
        fila.pop();
        if (nodo->getLeft() != NULL) fila.push(nodo->getLeft()); // agregamos nodo izquierdo
        if (nodo->getRight() != NULL) fila.push(nodo->getRight()); // agregamos nodo derecho
        if (calcNivel(nodo) != nivelActual) { // ocurrió un cambio de nivel
            std::cout << std::endl;
            nivelActual++;
        }
        std::cout << nodo->getData() << " ";
    }
}

int BST::calcNivel(nodeT* nodo){
    nodeT* p;
    int nivel = 0;
    p = root;
    while (p->getData() != nodo->getData()) {
        nivel++;
        p = p->getData() > nodo->getData() ? p->getLeft() : p->getRight();
    }
    return nivel;
}

#endif