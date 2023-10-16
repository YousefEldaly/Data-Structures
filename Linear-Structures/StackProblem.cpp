//
// Created by ahmed on 4/30/2023.
//

#include "StackProblem.h"
#include "stdexcept"
template <typename T>
void StackProblem<T>::push(T element) {
    q1.enqueue(element);
}

template <typename T>
T StackProblem<T>::pop() {
    if (q1.isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    while (q1.queueSize() > 1) {
        q2.enqueue(q1.dequeue());
    }
    T element = q1.dequeue();
    while (!q2.isEmpty()) {
        q1.enqueue(q2.dequeue());
    }
    return element;
}

template <typename T>
bool StackProblem<T>::isEmpty() const {
    return q1.isEmpty();
}

template <typename T>
void StackProblem<T>::clear() {
    q1.clear();
}

template <typename T>
void StackProblem<T>::print() const {
    q1.print();
}
