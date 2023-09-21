#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    int array[100];
    int *p;
    a = 5;
    b = 10;
    //c = 42;
    p = new int;
    cout << &a << " " << &b << " " << &c << " " << p << endl;
    delete p;
    //delete p; // ¿Qué sucede?
    cout << "Direccion de p " << p << endl;
    p = &a;
    *p = b;
    p++;
    *p = 42;
    p++; // p = &c;
    cout << a << " " << b << " " << c << endl;
    cout << *p << endl;
    //delete p; No se puede borrar memoria no dinamica
    p = array;
    cout << "Prueba arreglo" << endl;
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 100; i++) {
        *p = rand() % 100;
        p++;
    }
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    p = NULL;
    cout << "Direccion de p " <<  p << endl;
    //cout << "valor de p " << *p << endl;

    int *q;
    q = &c;
    p = &a;
    p++;
    p++;
    if (p == q) {
        cout << "p y q apuntan a donde mismo" << endl;
    }
    else {
        cout << "p y q apuntan a diferentes secicones de memoria" << endl;
    }

    cout << "Uso de array" << endl;
    int j = rand() % 100;
    if (array[j] == *(array + j)) {
        cout << "Son iguales array[j] == *(array + j)" << endl;
    }
    else {
        cout << "NO son iguales array[j] == *(array + j)" << endl;
    }
    cout << "Direccion de memoria de &array[j] " << &array[j] << endl;
    cout << "Direccion de array + j " << array + j << endl;

    p = new int[10];
    for (int i = 0; i < 10; i++) {
        *(p+i) = rand() % 50;
        cout << *(p+i) << " ";
    }
    cout << endl;
    delete[] p;
    for (int i = 1; i < 10; i++) {
        cout << *(p+1) << " ";
    }
    cout << endl;
}