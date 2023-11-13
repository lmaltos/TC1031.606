#ifndef GRAFO_H
#define GRAFO_H
#include "nodo.h"

class grafo {
  private:
    nodo *nodos = nullptr;
  public:
    grafo();
    ~grafo();
    nodo* addNodo(std::string);
    void addAdyacencia(nodo*,std::string);
    void DepthFirst();
    nodo* getNodoByID(std::string);
};

#endif