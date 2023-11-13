#include <iostream>
#include "grafo.h"
#include "../Bloque_2/stack2.h"

grafo::grafo() {

}

grafo::~grafo() {
    nodo *last = nodos, *next;
    while (last->Next() != nullptr) {
        next = last->Next();
        delete last;
        last = next;
    }
}

nodo* grafo::addNodo(std::string id) {
    nodo *nuevo;
    nuevo = new nodo(id);
    if (nodos == nullptr) {
        nodos = nuevo;
    }
    else 
    {
        nodo *last = nodos;
        while (last->Next() != nullptr) {
            last = last->Next();
        }
        last->setNext(nuevo);
    }
    return nuevo;
}

void grafo::addAdyacencia(nodo* n,std::string idAdyacencia) {
    n->addAdyacencia(idAdyacencia);
}

nodo* grafo::getNodoByID(std::string id) {
    nodo *last = nodos;
    while (last != nullptr) {
        if (last->Id() == id) {
            return last;
        }
        last = last->Next();
    }
    return nullptr;
}

void grafo::DepthFirst() {
    nodo *n = nodos;
    while (n != nullptr) {
        n->setEstatus(enEspera);
        n = n->Next();
    }
    n = nodos;
    stack2<nodo*> pila;
    while (n != nullptr) {
        if (n->Estatus() == enEspera) {
            pila.push(n);
            while (!pila.isEmpty()) {
                nodo *v = pila.Top();
                pila.pop();
                if (v->Estatus() == enEspera) {
                    v->setEstatus(procesado);
                    std::cout << v->Id() << " ";
                    adyacente *lista = v->getListaAdyacencias();
                    while (lista != nullptr) {
                        nodo *u = getNodoByID(lista->Id());
                        if (u->Estatus() == enEspera) {
                            pila.push(u);
                        }
                        lista = lista->Next();
                    }
                }
            }
        }
        n = n->Next();
    }
}