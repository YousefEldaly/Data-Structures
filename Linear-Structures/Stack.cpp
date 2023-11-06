#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack()
{
    head = tail = nullptr;
    length = 0;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "is Empty\n";
        return;
    }
    else if (length == 1)
    {
        delete head;
        tail = head = nullptr;
    }
    else
    {
        Node *curr, *prev;
        curr = head->next;
        prev = head;
        while (curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
        tail = prev;
    }
    length--;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return length == 0;
}

template <typename T>
int Stack<T>::stackSize() const
{
    return length;
}

template <typename T>
void Stack<T>::clear()
{
    length = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

template <typename T>
void Stack<T>::print() const
{
    if (isEmpty())
    {
        cout << "stack is Empty";
        return;
    }
    Node *curr;
    curr = head;
    while (true)
    {
        cout << curr->data << " ";
        if (curr == tail)
            break;
        curr = curr->next;
    }
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
int Stack<T>::top() const
{
    if (head == nullptr)
    {
        throw std::out_of_range("Stack is empty");
    }
    return tail->data;
}

template <typename T>
void Stack<T>::push(T element)
{
    Node *new_node = new Node;
    new_node->data = element;
    if (length == 0)
    {
        head = tail = new_node;
        new_node->next = nullptr;
    }
    else
    {
        tail->next = new_node;
        new_node->next = nullptr;
        tail = new_node;
    }
    length++;
}