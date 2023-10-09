#ifndef NODET_H
#define NODET_H
#include <cstddef>

class nodeT {
  private:
    int data;
    nodeT *left,*right;
  public:
    nodeT();
    nodeT(int);
    int getData();
    nodeT* getLeft() {return left;}
    nodeT* getRight() {return right;}
    void setData(int);
    void setLeft(nodeT* _left) {left = _left;}
    void setRight(nodeT* _right) {right = _right;}
};


nodeT::nodeT() {
    left = right = NULL;
}

nodeT::nodeT(int _data) {
    data = _data;
    left = right = NULL;
}

int nodeT::getData() {
    return data;
}

void nodeT::setData(int _data) {
    data = _data;
}
#endif