//
// Created by ahmed on 4/29/2023.
//

#include "Queue.h"
#include "SingleLinkedList.h"
#include "algorithm"
#include "iostream"
using namespace std;

template <typename T>
Queue<T>::Queue() {
    list = SingleLinkedList<T>();
}

template <typename T>
void Queue<T>::enqueue(T element) {
    list.insertAtTail(element);
}

template <typename T>
T Queue<T>::dequeue() {
    T element = list.retrieveAt(0);
    list.removeAtHead();
    return element;
}

template <typename T>
T Queue<T>::first() const {
    return list.retrieveAt(0);
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
int Queue<T>::queueSize() const {
    return list.listSize();
}

template <typename T>
void Queue<T>::clear() {
    list.clear();
}

template <typename T>
void Queue<T>::print() const {
    list.print();
}

template <typename T>
void selectionSort(Queue<T>& queue) {
    int size = queue.queueSize();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        T minValue = queue.dequeue();
        for (int j = i + 1; j < size; j++) {
            T current = queue.dequeue();
            if (current < minValue) {
                queue.enqueue(minValue);
                minIndex = j;
                minValue = current;
            } else {
                queue.enqueue(current);
            }
        }
        for (int k = 0; k < minIndex - i; k++) {
            queue.enqueue(queue.dequeue());
        }
        queue.enqueue(minValue);
    }
}