#include <iostream>
#include "stack.h"
#include "stack2.h"

using namespace std;

int main() {
    stack<string> pila;
    pila.push("ventana");
    pila.push("puerta");
    pila.push("pizzarron");
    pila.push("banco");
    pila.push("escritorio");
    cout << "pila.top() = " << pila.top() << endl;
    pila.pop();
    cout << "pila.pop()" << endl;
    cout << "pila.top() = " << pila.top() << endl;

    stack<int> pilaInt;
    pilaInt.push(123);
    for (int i = 0; i < MAX_SIZE; i++) {
        pilaInt.push(i+1);
    }
    cout << "pilaInt.isFull() ? " << pilaInt.isFull() << endl;
    while (!pilaInt.isEmpty()) {
        cout << pilaInt.top() << endl;
        pilaInt.pop();
    }

    stack<string> pila2;
    pila2.push("ventana");
    pila2.push("puerta");
    pila2.push("pizzarron");
    pila2.push("banco");
    pila2.push("escritorio");
    cout << "pila2.top() = " << pila2.top() << endl;
    pila2.pop();
    cout << "pila2.pop()" << endl;
    cout << "pila2.top() = " << pila2.top() << endl;

    stack2<int> pilaInt2;
    pilaInt2.push(123);
    for (int i = 0; i < MAX_SIZE; i++) {
        pilaInt2.push(i+1);
    }
    cout << "pilaInt2.isFull() ? " << pilaInt2.isFull() << endl;
    while (!pilaInt2.isEmpty()) {
        //cout << pilaInt2.Top() << endl;
        pilaInt2.pop();
    }
}