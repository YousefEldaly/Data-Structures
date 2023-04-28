//
// Created by Yusuf Aldaly on 4/28/2023.
//

#ifndef LINEAR_STRUCTURES_SINGLELINKEDLIST_H
#define LINEAR_STRUCTURES_SINGLELINKEDLIST_H



template <typename T> class SingleLinkedList {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head, *tail;
    int length;

public:
    SingleLinkedList();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index) const;
    void replaceAt(T new_element, int index);
    bool isExist(T element) const;
    bool isItemAtEqual(T element, int index) const;
    void swap(int first_item_idx, int second_item_idx);
    bool isEmpty() const;
    int listSize() const;
    void reverse();
    void clear();
    void print() const;

    ~SingleLinkedList();
};



#endif //LINEAR_STRUCTURES_SINGLELINKEDLIST_H
