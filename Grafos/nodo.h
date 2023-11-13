#ifndef NODO_H
#define NODO_H
#include <string>
#include "adyacente.h"

enum TipoEstatus {
    enEspera,
    procesado,
};

class nodo {
  private:
    std::string id;    
    nodo *next = nullptr;
    adyacente *listaAdyacencias = nullptr;
    void deleteAdyacencias(adyacente*);
    TipoEstatus estatus = enEspera;
  public:
    nodo(std::string);
    ~nodo();
    void setNext(nodo*);
    nodo* Next();
    std::string Id();
    void addAdyacencia(std::string);
    adyacente* getListaAdyacencias();
    void setEstatus(TipoEstatus);
    TipoEstatus Estatus();
};

#endif