#include <iostream>
#include "ArrayList.h"

using namespace std;


template <typename T>
ArrayList<T>::ArrayList() : ArrayList(DEFAULT_SIZE){
}
template <typename  T>
ArrayList<T>::ArrayList(int size) {
    if(size < 0)
        cout << "Can not create a list with this size\n";
    else{
        max_size = size;
        arr = new T[size];
        curr = 0;
        length = 0;
        cout << "list created with size\n";
    }
}

template <typename T>
void ArrayList<T>::insert(T element){
    insertAt(element, curr);
}

template <typename T>
void ArrayList<T>::insertAt(T element, int index) {
    if(isFull())
        cout << "List is Full.\n";
    else if(index < 0 || index > length)
        cout << "Out Of Range\n";
    else {
        for(int i = length; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = element;
        length++;
    }
}


template <typename T>
T ArrayList<T>::retrieveAt(int index) const{
    if(isEmpty())
        cout << "Can not retrieve form Empty list";
    else if(index < 0 || index > length)
        cout << "Out Of Range";
    else
        return arr[index];
}

template <typename T>
void ArrayList<T>::removeAt(int index) {
    if(isEmpty())
        cout << "Can not remove from an empty list.\n";
    else if(index < 0 || index > length)
        cout << "Out Of Range.\n";
    else {
        for(int i = index; i < length; i++)
            arr[i] = arr[i + 1];
        length--;
    }
}

template <typename T>
void ArrayList<T>::replaceAt(T new_element, int index) {
    if(isEmpty())
        cout << "Can not replace in an Empty list.\n";
    else if(index < 0 || index > length)
        cout << "Out Of Range";
    else
        arr[index] = new_element;
}

template <typename T>
bool ArrayList<T>::isItemAtEqual(T element, int index) const {
    if(isEmpty())
        cout << "List is Empty";
    else if(index < 0 || index > length)
        cout << "Out Of Range";
    else
        return arr[index] == element;
}


template <typename  T>
bool ArrayList<T>::isEmpty() const {
    return length == 0;
}



template <typename  T>
bool ArrayList<T>::isFull() const {
    return length == max_size;
}

template <typename  T>
int ArrayList<T>::listSize() const {
    return length;
}

template <typename T>
int ArrayList<T>::maxListSize() const {
    return max_size;
}

template <typename T>
void ArrayList<T>::clear() {
    length = curr = 0;
}

template <typename  T>
void ArrayList<T>::print() const {
    if (isEmpty())
        cout << "list is Empty";
    else
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void ArrayList<T>::append(T element) {
    if(length >= max_size)
        cout << "The List is FULL";
    insertAt(element, length);
}

template <typename T>
void ArrayList<T>::moveToStart() {
    curr = 0;
}

template <typename T>
void ArrayList<T>::moveToEnd() {
    curr = length;
}

template <typename T>
void ArrayList<T>::prev() {
    if(curr != 0)
        curr--;
}

template <typename T>
void ArrayList<T>::next() {
    if(curr < length)
        curr++;
}

template <typename T>
int ArrayList<T>::currPos() const {
    return curr;
}

template <typename T>
void ArrayList<T>::moveToPos(int pos) {
    if(pos < 0 || pos > length)
        cout << "Out Of Range";
    curr = pos;
}


template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] arr;
}
