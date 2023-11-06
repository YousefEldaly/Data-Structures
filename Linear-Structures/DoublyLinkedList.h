//
// Created by Yusuf Aldaly on 4/28/2023.
//

#ifndef LINEAR_STRUCTURES_DOUBLYLINKEDLIST_H
#define LINEAR_STRUCTURES_DOUBLYLINKEDLIST_H



template <typename T> class DoublyLinkedList{
private:
    struct Node {
        T data;
        Node *next;
        Node *prev;
    };
    Node *head, *tail;
    int length;

public:
    DoublyLinkedList();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void insertAfter(Node *prev_node, T data);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index) const;
    void replaceAt(T new_element, int index);
    bool isExist(T element) const;
    bool isItemAtEqual(T element, int index) const;
    void swap(int first_item_idx, int second_item_idx);
    void reverse();
    bool isEmpty() const;
    int listSize() const;
    void clear();
    void print() const;
    void printReverse();
};


#endif //LINEAR_STRUCTURES_DOUBLYLINKEDLIST_H
