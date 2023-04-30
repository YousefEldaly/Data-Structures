//
// Created by Yusuf Aldaly on 4/30/2023.
//
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
SingleLinkedList<T> CombineNodesBetweenZeros(const SingleLinkedList<T> &list) {
    SingleLinkedList<T> combined_list;
    int sum = 0;
    for(int i = 0; i < list.listSize(); i++) {
        if (i == 0) {
            continue;
        } else if (list.retrieveAt(i) == 0) {
            combined_list.insertAtTail(sum);
            sum = 0;
            continue;
        }
        sum += list.retrieveAt(i);
    }

    return combined_list;
}