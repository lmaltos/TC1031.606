#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST arbol;
    int dato;
    for (int i = 0; i < 50; i++) {
        dato = rand()%100;
        arbol.push(dato);
        cout << dato;
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
    cout << "Se agegan los numeros" << endl;
    for (int i = 0; i < 100; i++) {
        cout << arbol.search(i);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
    cout << "Buscar elemento a eliminar" << endl;
    int a = 0;
    while (!arbol.search(a)) {
        a++;
    }
    cout << "Primer elemento en nuestro arbol " << a << endl;
    a++;
    while (!arbol.search(a)) {
        a++;
    }
    cout << "Segundo elemento en nuestro arbol " << a << endl;
    cout << "borramos elemento " << a << endl;
    arbol.pop(a);
    for (int i = 0; i < 100; i++) {
        cout << arbol.search(i);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
}