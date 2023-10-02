#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

template <typename T>
class stack {
  private:
    T datos[MAX_SIZE];
    int tope;
  public:
    stack();
    void push(T);
    T top();
    void pop();
    bool isFull();
    bool isEmpty();
};

template <typename T>
stack<T>::stack() {
    tope = -1;
}

template <typename T>
void stack<T>::push(T dato) {
    tope++;
    datos[tope] = dato;
}

template <typename T>
T stack<T>::top() {
    return datos[tope];
}

template <typename T>
void stack<T>::pop() {
    if (tope > -1)
        tope--;
}

template <typename T>
bool stack<T>::isFull();
template <typename T>
bool stack<T>::isEmpty();

#endif