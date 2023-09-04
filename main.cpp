#include <iostream>
#include "myclass.h"
#include "Date.h"
#include "Registro.h"

using namespace std;

template <typename T>
T myMax(T a, T b)
{
    if (a < b)
        return b;
    return a;
}

float myMax(float a, float b)
{
    if (a < b)
        return b;
    return a;
}

int main2() {
    int a = 10,b = 9;
    float c = 5.5, d = 3.14;
    char e = 'a', f = 'G';

    cout << "myMax " << a << " " << b << " es " << myMax<int>(a,b) << endl;
    cout << "myMax " << c << " " << d << " es " << myMax(c,d) << endl;
    cout << "myMax " << e << " " << f << " es " << myMax<char>(e,f) << endl;
    return 0;
}

int main() {
    myClass<int,int> obji(4,5);
    myClass<float,char> objf(3.14,'+');
    myClass<char,float> objc('c',2.35);
}

void ComparaDate() {
    Date a,b;
    if (a > b) {

    }
}

void ComparaRegistro() {
    Registro reg1, reg2;
    if (reg1.getDate() > reg2.getDate()) {

    }
    if (reg1 > reg2) {
        
    }
}