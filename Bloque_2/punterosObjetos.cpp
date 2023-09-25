#include <iostream>
#include "Ejemplo.h"

using namespace std;

int main() {
    Ejemplo objeto1(34,56);
    Ejemplo *ptrObj;
    ptrObj = new Ejemplo(78);
    objeto1.getA();
    objeto1.setB(100);
    cout << "objeto1.a = " << objeto1.getA() << "\tobjeto1.ptr = " << objeto1.getPtr1() << endl;
    cout << "ptrObj->a = " << ptrObj->getA() << "\ttrObj->ptr = " << ptrObj->getPtr1() << endl;
    (*ptrObj).setA(10);
    cout << "(*ptrObj).setA(10);" << endl;
    cout << "ptrObj->a = " << ptrObj->getA() << "\ttrObj->ptr = " << ptrObj->getPtr1() << endl;
    delete ptrObj;

    ptrObj = &objeto1;
    ptrObj->getA();
}