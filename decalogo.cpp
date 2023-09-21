#include <iostream>

using namespace std;

void decalogo01();
void decalogo02();
void decalogo03();
void decalogo04();
void decalogo05();
void decalogo06();
void decalogo07();
void decalogo08();
void decalogo09();
void decalogo10();
void arreglo();

int main() {
    //decalogo10();
    arreglo();
}

// Por cada NEW debe haber un DELETE
void decalogo01() {
    string *p;
    p = new string; // NEW
    cout << "p = " << p << endl;
    *p = "hola";
    cout << "Despues de asignacion" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p; // DELETE
    //delete p; // segundo DELETE free(): double free detected, core dumped
    p = NULL;
    cout << "p = " << p << endl;
    //cout << "*p = " << *p << endl;
}

void decalogo02() {
    int *p, *q, *r;
    p = new int;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    q = r = p;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    *r = 41;
    cout << "*p = " << *p << endl;
    *q = 56;
    cout << "*p = " << *p << endl;
    delete r;
    cout << "Despues de delete" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    cout << "*p = " << *p << endl;
    
}

int* test03() {
    int *p;
    p = new int;
    *p = 42;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;
    return p;
}

void decalogo03() {
    int *q;
    cout << "&q = " << &q << endl;
    q = test03();
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    cout << "&q = " << &q << endl;
    delete q;
}

void decalogo04() {
    int *p, *q = NULL;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    //*p = 5; // Segmentation fault
    if (q != NULL) {
        cout << "*q = " << *q << endl;
    }
}

void decalogo05() {
    int *p, a;
    p = new int;
    *p = 3;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    a = 55;
    p = &a;
    cout << "p = " << p << endl;
    if (p != NULL) {
        delete p;
    }
}

void decalogo06() {
    int *p = NULL;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
}

void decalogo07() {
    int *p;
    p = new int;
    *p = 56;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "Nueva asigacion" << endl;
    delete p;
    p = new int;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
}

void decalogo08() {
    int *p, *q, a = 9;
    p = new int;
    *p = 3;
    q = p;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    q = &a;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    delete p;
}

void decalogo09() {
    int *p, *q, a = 9;
    p = new int;
    *p = 3;
    q = p;
    if (p == q) {
        cout << "p y q apuntan a la misma seccion de memoria" << endl;
    }
    else {
        cout << "p y q apuntan a diferentes secciones de memoria" << endl;
    }
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    q = &a;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    if (p != q){
        cout << "p y q apuntan a diferentes secciones de memoria" << endl;
    }
    else {
        cout << "p y q apuntan a la misma seccion de memoria" << endl;
    } 
    delete p;
}

void decalogo10() {
    int *p, a;
    p = new int;
    cout << "p = " << p << endl;
    a = 5;
    *p = a;
    cout << "*p = " << *p << endl;
    (*p)++;
    cout << "*p = " << *p << endl;
    *p += a;
    cout << "*p = " << *p << endl;
    *p *= 3;
    cout << "*p = " << *p << endl;
    *p /= 2;
    cout << "*p = " << *p << endl;
    delete p;
    cout << "p = " << p << endl;
}

void arreglo() {
    int arr[100];
    int *p, j;
    p = arr;
    cout << "arr = " << arr << endl;
    cout << "p = " << p << endl;
    j = rand() % 100;
    if (arr[j] == *(p + j)) {
        cout << "arr[j] y *(arr + j) Son equivalentes" << endl;
    }
    else {
        cout << "arr[j] y *(arr + j) no son equivalentes" << endl;
    }
    
    if (&arr[j] == (p + j)) {
        cout << "&arr[j] y (arr + j) Son equivalentes" << endl;
    }
    else {
        cout << "&arr[j] y (arr + j) no son equivalentes" << endl;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 50;
        cout << "arr[" << i << "] = " << arr[i] << endl;
        *p += 3;
        p++;
    }

    for (int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    cout << "arr = " << arr << endl;
    cout << "p = " << p << endl;
}