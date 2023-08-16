#ifndef MYCLASS_H
#define MYCLASS_H

template <class T, class D>
class myClass {
  private:
    T x;
    T y;
    D a;
    D b;
  public:
    myClass(T _x, T _y) : x(_x), y(_y) {};
    T getX();
    T getY() {return y;};
    void setA(D _a) {a = _a;}
    void setB(D _b) {b = _b;}
};

template <class T, class D>
T myClass<T,D>::getX(){
    return x;
}
#endif