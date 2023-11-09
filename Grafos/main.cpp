#include <iostream>
#include <fstream>
#include "grafo1.h"

using namespace std;

int main() {
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
}