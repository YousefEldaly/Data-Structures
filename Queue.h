//
// Created by ahmed on 4/29/2023.
//

#ifndef LINEAR_STRUCTURES_QUEUE_H
#define LINEAR_STRUCTURES_QUEUE_H


class Queue {
private:
    T* arr;
    int front, rear, capacity;

public:
    Queue(int size);
    void enqueue(T element);
    T dequeue();
    T first();
    bool isEmpty();
    int queueSize();
    void clear();
    void print();

    };


#endif //LINEAR_STRUCTURES_QUEUE_H
