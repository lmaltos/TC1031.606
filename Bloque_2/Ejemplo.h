#ifndef EJEMPLO_H
#define EJEMPLO_H
#include <iostream>

class Ejemplo {
  private:
    int a,b,c,d;
    float x,y,z;
    char s,t,u;
    int *ptr;
    float *ptrf;
  public:
    Ejemplo();
    Ejemplo(int);
    Ejemplo(int,int);
    ~Ejemplo();
    int getA() {return a;}
    float getX() {return x;}
    char getS() {return s;}
    void setA(int);
    void setB(int);
    int* getPtr1() {return ptr;}
    float* getPtr2() {return ptrf;}
};

Ejemplo::Ejemplo() {
    a = b = 0;
    ptr = NULL;
    ptrf = NULL;
    std::cout << "Constructor Ejemplo()" << std::endl;
}

Ejemplo::Ejemplo(int _a) {
    a = _a;
    ptr = new int[a];
    ptrf = NULL;
    std::cout << "Constructor Ejemplo(int)" << std::endl;
}

Ejemplo::Ejemplo(int _a, int _b) {
    a = _a;
    ptr = new int[a];
    b = _b;
    ptrf = new float[b];
    std::cout << "Constructor Ejemplo(int, int)" << std::endl;
}

Ejemplo::~Ejemplo() {
    std::cout << "Se llama destructor ~Ejemplo()" << std::endl;
    delete[] ptr;
    delete[] ptrf;
    std::cout << "ptr = " << ptr << "\tptrf = " << ptrf << std::endl; 
    ptr = NULL;
    ptrf = NULL;
}

void Ejemplo::setA(int _a) {
    a = _a;
    std::cout << "delete[] ptr = " << ptr << ";" << std::endl;
    delete[] ptr;
    ptr = new int[a];
}

void Ejemplo::setB(int _b) {
    b = _b;
    std::cout << "delete[] ptrf = " << ptrf << ";" << std::endl;
    delete[] ptrf;
    ptrf = new float[b];
}

#endif