#include "grafo1.h"
#include "../Bloque_2/queue2.h"
#include <iostream>

grafo1::grafo1() {
    nodos = 0;
    A = nullptr;
}

grafo1::grafo1(int n) {
    nodos = n;
    A = nullptr;
    changeAsize();
}

grafo1::grafo1(int n, bool **_A) {
    nodos = n;
    A = nullptr;
    changeAsize();
    for (int i = 0; i < nodos; i++) {
        for (int j = 0; j < nodos; j++) {
            A[i][j] = _A[i][j];
        }
    }
}

grafo1::~grafo1() {
    deleteA();
}

void grafo1::changeAsize() {
    deleteA();
    A = new bool*[nodos];
    for (int i = 0; i < nodos; i++) {
        A[i] = new bool[nodos];
        for (int j = 0; j < nodos; j++) A[i][j] = false; // inicializamos en false
    }
}

void grafo1::deleteA() {
    if (A == nullptr)
        return;
    for (int i = 0; i < nodos; i++) {
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
}

void grafo1::adyacencia(int i,int j) {
    A[i][j] = true;
}

void grafo1::BreadthFirst() {
    bool *visitado;
    // inicializar el estatus de todos los nodos a "en espera" o no vistiados
    visitado = new bool[nodos];
    for (int i = 0; i < nodos; i++) visitado[i] = false;
    // para cada nodo
    // si el estatus del nodo es "en espera" insertarlo a la fila
    queue2<int> fila;
    for (int n = 0; n < nodos;n++) {
        if (visitado[n] == false) {
            fila.push(n);
            visitado[n] = true;
            while (!fila.isEmpty()) {
                int nodo = fila.front();
                fila.pop();
                std::cout << nodo << " ";
                for (int i = 0; i < nodos; i++) {
                    if (A[nodo][i]) { // existe adyacencia entre nodo nodo y nodo i
                        if (visitado[i] == false) {
                            fila.push(i);
                            visitado[i] = true;
                        }
                    }
                }
            }
        }
    }
    delete[] visitado;
}