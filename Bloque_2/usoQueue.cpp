#include <iostream>
#include "queue2.h"

using namespace std;

int main() {
    queue2<float> fila;
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;
    fila.push(3.1);
    fila.push(3.14);
    fila.push(3.145);
    fila.push(3.1459);
    fila.push(3.4);
    fila.push(3.45);
    fila.push(3.46);
    fila.push(3.47);
    fila.push(3.48);
    cout << "Se agregan elementos" << endl;
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;
    while (!fila.isEmpty()) {
        //cout << fila.front() << endl;
        fila.pop();
    }
    cout << "Se remueven elementos" << endl;
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;

}