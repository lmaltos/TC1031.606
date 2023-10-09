#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST arbol;
    int dato;
    for (int i = 0; i < 50; i++) {
        dato = rand()%100;
        arbol.push(dato);
        cout << dato << endl;
    }
    for (int i = 1; i <= 100; i++) {
        cout << "search(" << i << ") \t" << arbol.search(i) << endl;
    }
}