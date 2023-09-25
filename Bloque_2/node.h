#ifndef NODE_H
#define NODE_H

template <class T>
class node {
  public:
    node(T);
    node(T,node<T> *);
    T getData();
    node<T>* getNext();
    void setData(T);
    void setNext(node<T>*);
  private:
    T data;
    node<T> *next;
};

template <class T>
node<T>::node(T _data) {
  data = _data;
  next = 0;
}

template <class T>
node<T>::node(T _data, node<T>* _next) {
  data = _data;
  next = _next;
}

template <class T>
T node<T>::getData() {
  return data;
}

template <class T>
node<T>* node<T>::getNext() {
  return next;
}
template <class T>
void node<T>::setData(T _data) {
  data = _data;
}

template <class T>
void node<T>::setNext(node<T>* _next) {
  next = _next;
}

#endif