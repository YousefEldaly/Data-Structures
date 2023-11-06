//
// Created by Yusuf Aldaly on 5/1/2023.
//
#include <bits/stdc++.h>
#include <iostream>
#include "cstdarg"
#include "SingleLinkedList.h"

using namespace std;

template <typename T>
struct compare {
    bool operator()(typename SingleLinkedList<T>:: Node* a,
            typename SingleLinkedList<T>:: Node* b){

        return a->data >= b->data;
    }
};
template <typename T>
SingleLinkedList<T> mergeSortedLists(typename SingleLinkedList<T>::Node* lists[], int num_of_lists)
{
    SingleLinkedList<T> merged_list;

    priority_queue<typename SingleLinkedList<T>::Node*, vector<typename SingleLinkedList<T>::Node*>, compare<T>> pq;

    for (int i = 0; i < num_of_lists; i++)
        if (lists[i] != NULL)
            pq.push(lists[i]);


    if (pq.empty()){
        return merged_list;
    }
cout << "daddy\n";
    typename SingleLinkedList<T>::Node* dummy;
    typename SingleLinkedList<T>::Node* last = dummy;

    while (!pq.empty()) {
        typename SingleLinkedList<T>::Node* curr = pq.top();
        pq.pop();
//        last->next = curr;
//        last = last->next;
        merged_list.insertAtTail(curr->data);

        if (curr->next != NULL){
            pq.push(curr->next);
        }

    }

    return merged_list;
}











//#include <bits/stdc++.h>

// Trying Variadic function and pointers to pointers
/*
template <typename T>
SingleLinkedList<T> MergeLists(typename SingleLinkedList<T>::Node** head, ...) {

    priority_queue<typename SingleLinkedList<T>::Node**, vector<typename SingleLinkedList<T>::Node**> ,compare<T>> pq, pq2;
    SingleLinkedList<T> merged_list;

    va_list args;
    va_start(args, head);

    typename SingleLinkedList<T>::Node** s;
    int args_length = 0;
    vector<typename SingleLinkedList<T>::Node**> lists;

    for(s = head; s !=NULL; s = va_arg(args, typename SingleLinkedList<T>::Node**)){
        lists.push_back(s);
        args_length++;
    }

    for(int i = 0; i < args_length; i++) {
        pq.push(lists[i]);
    }

    if(pq.empty())
        return merged_list;

    typename SingleLinkedList<T>::Node* tmp = new typename SingleLinkedList<T>::Node;
    typename SingleLinkedList<T>::Node* last = tmp;


    if(pq.empty())
        cout << "is empty\n";
    for (int i = 0; i < 3; i++){
        typename SingleLinkedList<T>::Node* rr = *(pq.top());
        pq.pop();
        cout << rr->data << " ";
    }
    cout << endl;


pq.pop();
    pq.pop();

    typename SingleLinkedList<T>::Node* daddy = *(pq.top());
    while(daddy != NULL){
        cout << daddy->data << " ";
        daddy = daddy->next;
    }
    while(!pq.empty()){
        typename SingleLinkedList<T>::Node* curr = *(pq.top());
        cout << curr->data;
        pq.pop();
        last->next = curr;
        last = last->next;

        if(curr->next != NULL){
            cout << curr->next->data << " ";
            pq.push(&(curr->next)); //////// codes runs into infinite loop here
        }
    }
    for (int i = 0; i < 3; i++){
        typename SingleLinkedList<T>::Node* rr = *(pq.top());
        cout << rr->data << " ";
        pq.pop();
    }

    va_end(args);

    return merged_list;

}
*/






