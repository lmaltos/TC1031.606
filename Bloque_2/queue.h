#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_MAX_SIZE 8

template <typename T>
class queue {
  private:
    T datos[QUEUE_MAX_SIZE];
    int Frente,Final;
  public:
    queue();
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
};

template <typename T>
queue<T>::queue() {
    Frente = Final = -1;
}

template <typename T>
void queue<T>::push(T dato) {
    Final++;
    //if (Final == QUEUE_MAX_SIZE) Final = 0;
    //Final = Final % QUEUE_MAX_SIZE;
    Final %= QUEUE_MAX_SIZE;
    datos[Final] = dato;
}

template <typename T>
void queue<T>::pop() {
    Frente++;
    if (Frente = QUEUE_MAX_SIZE) Frente = 0;
    //Frente = Frente % QUEUE_MAX_SIZE;
    //Frente %= QUEUE_MAX_SIZE;
}

template <typename T>
T queue<T>::front() {
    return datos[Frente];
}

template <typename T>
bool queue<T>::isEmpty() {
    return Frente == -1;
}
template <typename T>
bool queue<T>::isFull() {
    return (Final + 1)% QUEUE_MAX_SIZE == Frente;
}

#endif