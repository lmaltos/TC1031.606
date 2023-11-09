#include <iostream>
#include "AVL.h"

int main() {
    AVL arbol;
    for (int i = 1; i < 65; i++) {
        arbol.push(i);
    }
    arbol.printPorNivel();
}