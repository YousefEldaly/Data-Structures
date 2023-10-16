//
// Created by ahmed on 4/29/2023.
//

#ifndef LINEAR_STRUCTURES_QUEUE_H
#define LINEAR_STRUCTURES_QUEUE_H
#include "SingleLinkedList.h"
template <typename T>
class Queue {
private:
    SingleLinkedList<T> list;

public:
    Queue();
    void enqueue(T element);
    T dequeue();
    T first() const;
    bool isEmpty() const;
    int queueSize() const;
    void clear();
    void print() const;
    void selectionSort(Queue<T>& q);
};



#endif //LINEAR_STRUCTURES_QUEUE_H
