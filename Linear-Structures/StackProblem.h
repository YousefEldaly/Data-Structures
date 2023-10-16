//
// Created by ahmed on 4/30/2023.
//

#ifndef NEW_FOLDER_STACKPROBLEM_H
#define NEW_FOLDER_STACKPROBLEM_H
#include "Queue.h"

template<typename T>

class StackProblem {
private:
    Queue<T> q1, q2;

public:
    void push(T element);
    T pop();
    bool isEmpty() const;
    void clear();
    void print() const;
};

#endif //NEW_FOLDER_STACKPROBLEM_H
