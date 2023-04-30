//
// Created by Ahmed Ashraf on 4/29/2023.
//

#ifndef LINEAR_STRUCTURES_STACK_H
#define LINEAR_STRUCTURES_STACK_H

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head, *tail;
    int length;

public:
    Stack();
    void push(T element);  // <<<<<<<<<
    void pop();            // <<<<<<<<<<
    bool isEmpty() const;  // <<<<<<<<<<<<<<<
    int stackSize() const; // <<<<<<<<<<<<<<<
    int top() const;       // <<<<<<<<<<<
    void clear();          // <<<<<<<<<
    void print() const;    // <<<<<<<<<

    ~Stack();
};

#endif // LINEAR_STRUCTURES_STACK_H