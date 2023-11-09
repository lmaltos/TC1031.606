#ifndef GRAFO1_H
#define GRAFO1_H

/// @brief Representacion de grafo con matriz de adyacencia 
class grafo1 {
  private:
    int nodos;
    bool **A;
    void changeAsize();
    void deleteA();
  public:
    grafo1();
    grafo1(int);
    grafo1(int,bool**);
    ~grafo1();
    void adyacencia(int,int);
    void BreadthFirst();
};

#endif