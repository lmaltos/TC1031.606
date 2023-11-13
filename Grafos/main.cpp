#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo1.h"
#include "grafo.h"

using namespace std;

int mainMA() {
    grafo1 grafo(10);
    ifstream archivo;
    int n,a;
    
    archivo.open("EjemploGrafoMA.txt");
    archivo >> n;
    for (int i = 0; i< n;i++){
        for (int j = 0; j < n; j++) {
            archivo >> a;
            if (a == 1) {
                grafo.adyacencia(i,j);
                //cout << "adyacencia nodo " << i << " con nodo " << j << endl;
            }
        }
    }
    archivo.close();
    grafo.BreadthFirst();
    cout << endl;
    return 0;
}

int main() {
    grafo G;
    ifstream archivo;
    string id, idAdyacencia;
    string linea;
    nodo *nodo;
    
    archivo.open("EjemploGrafoLA.txt");
    while (!archivo.eof()) {
        archivo >> id;
        nodo = G.addNodo(id);
        cout << "Se crea nodo " << id << endl;
        getline(archivo,linea);
        stringstream ss(linea);
        while (!ss.eof()) {
            ss >> idAdyacencia;
            G.addAdyacencia(nodo, idAdyacencia);
            cout << "se agrega adyacencia entre nodo " << id << " y nodo " << idAdyacencia << endl;
        }
    }
    archivo.close();
    G.DepthFirst();
    cout << endl;
}