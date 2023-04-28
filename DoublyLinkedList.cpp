//
// Created by Yusuf Aldaly on 4/28/2023.
//

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = tail = nullptr;
    length = 0;
}


template <typename T>
void DoublyLinkedList<T>::insertAtHead(T element) {
    cout << "inserted at head\n";
    Node *new_node = new Node;
    new_node->data = element;
    if (length == 0) {
        head = tail = new_node;
        new_node->next = new_node->prev = nullptr;
    } else {
        new_node->next = head;
        new_node->prev = nullptr;
        head->prev = new_node;
        head = new_node;
    }
    length++;
}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(T element) {
    Node *new_node = new Node;
    new_node->data = element;
    if (length == 0){
        head = tail = new_node;
        new_node->next = new_node->prev = nullptr;
    } else {
        new_node->next = nullptr;
        new_node->prev = tail;
        tail->next  = new_node;
        tail = new_node;
    }
    length++;
}

template <typename T>
void DoublyLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index >= length){
        cout << "Out Of Range";
        return;
    } else if (index == 0){
        insertAtHead(element);
    } else if (index == length) {
        insertAtTail(element);
    } else {
        Node *new_node = new Node;
        new_node->data = element;
        Node *curr = head;
        for (int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        new_node->next = curr->next;
        new_node->prev = curr;
        curr->next->prev = new_node;
        curr->next = new_node;
        curr->next = new_node;
        length++;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAfter(Node *prev_node, T data) {
    if (prev_node == nullptr) {
        cout << "The Given Nod is NULL, Cannot add data";
        return;
    } else if (prev_node == tail) {
        insertAtTail(data);
    } else {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = prev_node->next;
        new_node->prev = prev_node;
        new_node->next->prev = new_node;
        prev_node->next = new_node;
        length++;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeAtHead() {
    if (isEmpty()){
        cout << "List is Empty";
        return;
    } else if (length == 1){
        delete head;
        head = tail = nullptr;
    } else {
        Node *curr = head;
        head = head->next;
        head->prev = nullptr;
        delete curr;
    }
    length--;
}

template <typename T>
void DoublyLinkedList<T>::removeAtTail() {
    if (isEmpty()){
        cout << "List is Empty";
        return;
    } else if (length == 1) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node *curr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete curr;
    }
    length--;
}

template <typename T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length){
        cout << "Out of Range";
        return;
    }
    else if (isEmpty()){
        cout << "List is Empty";
        return;
    } else if (index == 0) {
        removeAtHead();
    } else if (index == length) {
        removeAtTail();
    } else {
        Node *curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;
    }
}

template <typename T>
T DoublyLinkedList<T>::retrieveAt(int index) const {
    if (index < 0 || index >= length) {
        cout << "Out Of range";
        return 0; /////////////////Exception handling should be added
    } else if (isEmpty()){
        cout << "list is empty"; /////////////////////Exception
        return 0;
    }
    Node *curr = head;
    int count = 0;
    while (count < index){
        curr = curr->next;
        count++;
    }

    return curr->data;
}

template <typename T>
void DoublyLinkedList<T>::replaceAt(T new_element, int index) {
    if (index < 0 || index >= length) {
        cout << "Out Of Range";
        return;
    }
    Node *curr = head;
    int count = 0;
    while (count < index){
        curr = curr->next;
        count++;
    }
    curr->data = new_element;

    return;
}

template <typename T>
bool DoublyLinkedList<T>::isExist(T element) const {
    Node *curr = head;
    while (curr != nullptr){
        if (curr->data == element)
            return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::isItemAtEqual(T element, int index) const {
    if (index < 0 || index >= length) {
        cout << "Out of Range";
        return 0;
    }
    Node *curr = head;
    int count = 0;
    while (count != index) {
        curr = curr->next;
        count++;
    }
    if (curr->data == element)
        return true;
    else
        return false;
}

template <typename T>
void DoublyLinkedList<T>::swap(int first_item_idx, int second_item_idx) {
    if (first_item_idx < 0 || first_item_idx >= length
        || second_item_idx < 0 || second_item_idx >= length){
        cout << "Out Of Range";
        return;
    } else if (first_item_idx == 0 && second_item_idx == length - 1) {
        Node *curr = head;
        tail->next = head->next;
        head->next->prev = tail;
        head->next = nullptr;
        head->prev = tail->prev;
        tail->prev->next = head;
        tail->prev = nullptr;
        head = tail;
        tail = curr;
    } else if (first_item_idx == 0) {
        Node *node2 = head;
        Node *after_head = head->next;
        for (int i = 0; i < second_item_idx; i++) {
            node2 = node2->next;
        }
        node2->next->prev = head;
        head->next = node2->next;
        node2->next = after_head;
        after_head->prev = node2;
        node2->prev->next = head;
        head->prev = node2->prev;
        node2->prev = nullptr;
        head = node2;
    } else if (second_item_idx == length - 1){
        Node *node1 = head;
        Node *curr = tail->prev;
        for (int i = 0; i < first_item_idx; i++) {
            node1 = node1->next;
        }
        tail->next = node1->next;
        node1->next->prev = tail;
        node1->next = nullptr;
        curr->next = node1;
        node1->prev->next = tail;
        tail->prev = node1->prev;
        node1->prev = curr;
        tail = node1;
    } else {
        Node *node1, *node2, *curr;
        node1 = node2 = curr = head;
        for (int i = 0; i < first_item_idx; i++) {
            node1 = node1->next;
        }
        curr = node1->next;

        for (int i = 0; i < second_item_idx; i++) {
            node2 = node2->next;
        }
        node1->next = node2->next;
        node2->next = curr;
        curr->prev = node2;
        node1->next->prev = node1;
        node1->prev->next = node2;
        node2->prev->next = node1;
        while (curr->next != node1) {
            curr = curr->next;
        }
        node2->prev = node1->prev;
        node1->prev = curr;
    }
}


template <typename T>
void DoublyLinkedList<T>::reverse() {
    Node *temp = nullptr;
    Node *current = head;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL){
        current = tail;
        tail = head;
        head = temp->prev;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
int DoublyLinkedList<T>::listSize() const {
    return length;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    length = 0;
    Node *curr = head;
    while (curr != nullptr) {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    if (isEmpty()){
        cout << "List is Empty";
        return;
    }
    Node *curr;
    curr = head;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}


template <typename T>
void DoublyLinkedList<T>::printReverse() {
    if (isEmpty()) {
        cout << "List is Empty";
    } else {
        Node *curr = tail;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
}
#include "DoublyLinkedList.h"
