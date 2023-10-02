#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> lista;
    lista.addFist(1);
    lista.addFist(2);
    lista.addFist(3);
    lista.addFist(4);
    lista.addFist(5);
    lista.addFist(6);
    lista.print();
    lista.addLast(1);
    lista.addLast(2);
    lista.addLast(3);
    lista.addLast(4);
    lista.addLast(5);
    //cout << "lista.getByPos(4) = " << lista.getByPos(4) << endl;
    cout << "lista[4] = " << lista[4] << endl;
    cout << "lista[5] = " << lista[5] << endl;
    cout << "lista[6] = " << lista[6] << endl;
    cout << "lista[7] = " << lista[7] << endl;
    lista.print();
}