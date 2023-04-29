//
// Created by ahmed on 4/29/2023.
//

#include "Queue.h"
Queue(int size) {
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
}

void enqueue(T element) {
    if (rear == capacity - 1) {
        cout << "Queue is full!" << endl;
        return;
    }
    rear++;
    arr[rear] = element;
}

T dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return T();
    }
    T element = arr[front];
    front++;
    return element;
}

T first() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return T();
    }
    return arr[front];
}

bool isEmpty() {
    return (rear < front);
}

int queueSize() {
    return (rear - front + 1);
}

void clear() {
    front = 0;
    rear = -1;
}

void print() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}