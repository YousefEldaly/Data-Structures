#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

template <typename T>
SingleLinkedList<T>::SingleLinkedList() {
    head = tail = nullptr;
    length = 0;
    current_pos = 0;
}

template <typename T>
void SingleLinkedList<T>::insertAtHead(T element) {
    Node *new_node = new Node;
    new_node->data = element;
    if(length == 0){
        head = tail = new_node;
        new_node->next = nullptr;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    length++;
}


template <typename T>
void SingleLinkedList<T>::insertAtTail(T element) {
    Node *new_node = new Node;
    new_node->data = element;
    if(length == 0){
        head = tail = new_node;
        new_node->next = nullptr;
    }
    else {
        tail->next = new_node;
        new_node-> next = nullptr;
        tail = new_node;
    }
    length++;
}

template <typename T>
void SingleLinkedList<T>::insertAt(T element, int index) {
    if(index < 0 || index > length)
        cout << "Out Of Range";
    else {
        Node *new_node = new Node;
        new_node->data = element;
        if (index == 0)
            insertAtHead(element);
        else if (index == length)
            insertAtTail(element);
        else {
            Node *curr;
            curr = head;
            for (int i = 1; i < index; i++){
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
            length++;
        }
    }
}



template <typename T>
void SingleLinkedList<T>::removeAtHead() {
    if(isEmpty())
        return;
    else if (length == 1)
        delete head;
    else {
        Node *curr;
        curr = head;
        head = head->next;
        delete curr;
    }
    length--;
}

template <typename T>
void SingleLinkedList<T>::removeAtTail() {
    if(isEmpty()){
        cout << "is Empty\n";
        return;}
    else if(length == 1) {
        delete head;
        tail = head = nullptr;
    }
    else {
        Node *curr, *prev;
        curr = head->next;
        prev = head;
        while(curr != tail){
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
void SingleLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Out Of Range";
        return;
    }
    else if (index == 0)
        removeAtHead();
    else if (index == length)
        removeAtTail();
    else{
        Node *curr, *prev, *node_to_del;
        curr = head->next->next;
        node_to_del = head->next;
        prev = head;
        int count = 2;
        while (count <= index){
            curr = curr->next;
            node_to_del = node_to_del->next;
            prev = prev->next;
            count++;
        }
        prev->next = curr;
        delete node_to_del;
    }
    length--;
}

template <typename T>
T SingleLinkedList<T>::retrieveAt(int index) const {
    if (index < 0 || index >= length) {
        cout << "Out Of range";
        return 0; /////////////////Exception handling should be added
    } else if (isEmpty()){
        cout << "list is empty"; /////////////////////Exception
        return 0;
    }
    Node *curr = head;
    for (int count = 0; count < index; count++){
        curr = curr->next;
    }

    return curr->data;
}

template <typename T>
void SingleLinkedList<T>::replaceAt(T new_element, int index) {
    if (index < 0 || index >= length) {
        cout << "Out Of Range";
        return;
    }
    Node *curr = head;
    for (int count = 0; count < index; count++){
        curr = curr->next;
    }
    curr->data = new_element;

    return;
}

template <typename T>
bool SingleLinkedList<T>::isExist(T element) const {
    Node *curr = head;
    while (curr != nullptr){
        if (curr->data == element)
            return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
bool SingleLinkedList<T>::isItemAtEqual(T element, int index) const {
    if (index < 0 || index >= length) {
        cout << "Out of Range";
        return 0;
    } else if (isEmpty()){
        cout << "List is empty";
    } else {
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
    return false;
}


template <typename T>
void SingleLinkedList<T>::swap(int first_item_idx, int second_item_idx) {
    if (first_item_idx < 0 || first_item_idx >= length
        || second_item_idx < 0 || second_item_idx >= length){
        cout << "Out Of Range";
        return;
    }


    if (first_item_idx == 0 && second_item_idx == length - 1){
        Node *curr = head;
        while (curr->next != tail){
            curr = curr->next;
        }
        tail->next = head->next;
        head->next = nullptr;
        curr->next = head;
        curr = tail;
        tail = head;
        head = curr;
    } else if (first_item_idx == 0){
        Node *prev1, *prev2, *node2;
        prev2 = head;
        node2 = prev1 = head->next;

        for (int count = 1; count < second_item_idx; count ++){
            node2 = node2->next;
            prev2 = prev2->next;
        }
        head->next = node2->next;
        node2->next = prev1;
        prev2->next = head;
        head = node2;
    } else if(second_item_idx == length - 1){
        Node *prev1, *prev2, *node1;
        node1 = head->next;
        prev1 = prev2 = head;

        while (prev2->next != tail){
            prev2 = prev2->next;
        }

        for (int count = 1; count < first_item_idx; count++){
            node1 = node1->next;
            prev1 = prev1->next;
            count++;
        }
        tail->next = node1->next;
        node1->next = nullptr;
        prev1->next = tail;
        prev2->next = node1;
        tail = node1;
    } else {
        Node *prev1, *prev2, *node1, *node2;
        prev1 = prev2 = head;
        node1 = node2 = head->next;

        int count = 1;
        while (count < second_item_idx){
            node2 = node2->next;
            prev2 = prev2->next;
            count++;
        }
        count = 1;
        while (count < first_item_idx){
            node1 = node1->next;
            prev1 = prev1->next;
            count++;
        }
        prev1->next = prev2->next;
        prev2->next = node1;
        prev2 = node2->next;
        node2->next = node1->next;
        node1->next = prev2;
    }
}

template <typename T>
bool SingleLinkedList<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
int SingleLinkedList<T>::listSize() const {
    return length;
}

template <typename T>
void SingleLinkedList<T>::reverse() {
    Node *curr, *next, *prev;
    curr = head;
    next = prev = nullptr;
    bool at_head = 1;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        if (at_head){
            tail = curr;
            at_head = 0;
        }
        curr = next;
    }
    head = prev;
}

template <typename T>
void SingleLinkedList<T>::clear() {
    length = 0;
    Node *curr = head;
    while (curr != nullptr) {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

template <typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::getHeadAddress() const {
    Node* head_node = head;
    return head_node;
}


template <typename T>
void SingleLinkedList<T>::print() const {
    if (isEmpty()){
        cout << "List is Empty";
        return;
    }
    Node *curr;
    curr = head;
    while(true) {
        cout << curr->data << " ";
        if(curr == tail)
            break;
        curr = curr->next;
    }
}
template <typename T>
int SingleLinkedList<T>::currentPos() {
    return current_pos;
}

template <typename T>
void SingleLinkedList<T>::moveToStart() {
    current_pos = 0;
}

template <typename T>
void SingleLinkedList<T>::moveToEnd() {
    current_pos = length - 1;
}

template <typename T>
void SingleLinkedList<T>::moveToPos(int index) {
    current_pos = index;
}
template <typename T>
SingleLinkedList<T>::~SingleLinkedList(){
    clear();
}

