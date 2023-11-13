#include "nodo.h"

nodo::nodo(std::string _id) {
    id = _id;
}

nodo::~nodo() {
    deleteAdyacencias(listaAdyacencias);
}

void nodo::deleteAdyacencias(adyacente *adyacencia) {
    if (adyacencia != nullptr) {
        deleteAdyacencias(adyacencia->Next());
        delete adyacencia;
    }
}

void nodo::setNext(nodo* _next) {
    next = _next;
}

nodo* nodo::Next() {
    return next;
}

std::string nodo::Id() {
    return id;
}

void nodo::addAdyacencia(std::string idAdyacente) {
    adyacente *adyacencia;
    adyacencia = new adyacente(idAdyacente);
    if (listaAdyacencias == nullptr) {
        listaAdyacencias = adyacencia;
        return;
    }
    adyacente *last = listaAdyacencias;
    while (last->Next() != nullptr) {
        last = last->Next();
    }
    last->setNext(adyacencia);
}

adyacente* nodo::getListaAdyacencias(){
    return listaAdyacencias;
}

void nodo::setEstatus(TipoEstatus _estatus) {
    estatus = _estatus;
}

TipoEstatus nodo::Estatus() {
    return estatus;
}