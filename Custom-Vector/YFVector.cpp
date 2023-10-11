#include "YFVector.h"
#include "exceptions.h"



//*******************************CONSTRUCTORS AND BIG 4*********************************************

// Default constructor
template<typename T>
inline YFVector<T>::YFVector(): arr(new T[1]), _capacity(1),_size(0) {
}

// Parametrized constructor (capacity)
template<typename T>
inline YFVector<T>::YFVector(int n): arr(new T[n]), _capacity(n), _size(0) {
}

// Initialize parametrized constructor (array,size)
template<typename T>
inline YFVector<T>::YFVector(T* data, int n): arr(data), _capacity(n), _size(n){
}

// Copy Constructor
template<typename T>
inline YFVector<T>::YFVector(const YFVector& anotherVec){
        copyInternalData(anotherVec);
}

// Destructor
template<typename T>
inline YFVector<T>::~YFVector() {
    delete[] arr;
}

// Copy Assignment
template<typename T>
inline YFVector<T>& YFVector<T>::operator= (const YFVector& anotherVec){
    if(this != &anotherVec){
        delete [] arr;
        copyInternalData(anotherVec);
    }
    return *this;

    }

// Move Assignment
template<typename T>
inline YFVector<T>& YFVector<T>::operator=(YFVector&& anotherVec) noexcept{
    if(this != &anotherVec){
        delete[] arr;
        arr = anotherVec.arr;
        _size = anotherVec._size;
        _capacity = anotherVec._capacity;
        anotherVec.arr = nullptr;
        anotherVec._size = 0;
        anotherVec._capacity = 0;
    }
    return *this;
}

//*****************************ACCESS OPERATIONS***********************************

// Index operator
template<typename T>
inline T& YFVector<T>::operator[](int index){
        if(index >= _size || index < 0)
            throw outOfRange();
        else
            return arr[index];
}

//***************************************MODIFYING OPERATIONS************************************

// Push Back Operator
template<typename T>
inline void YFVector<T>::push_back(T data) {
    if (_size == _capacity) {
        resize();
    }

    arr[_size] = data;
    _size++;
}

// Pop Back Operator
template<typename T>
inline T YFVector<T>::pop_back() {
        if(_size == 0){
            throw noPop();
        }
        else
            return arr[--_size];

}
// erase an interval
template<typename T>
inline void YFVector<T>::erase(iterator iter1, iterator iter2){
        if(iter1 < begin() || iter1 > end() || iter2 < iter1 || iter2 > end()){
            throw outOfRange();
        }

        YFVector tmp;
        for(auto iter = begin(); iter != iter1; ++iter){
            tmp.push_back(*iter);
        }

        for(auto iter = iter2; iter != end(); ++iter){
            tmp.push_back(*iter);
        }
        swap(*this, tmp);
}

// Erase item at Iterator
template<typename T>
inline void YFVector<T>::erase(iterator iter){
    erase(iter, iter+1);
}

// Clear Vector Elements
template<typename T>
inline void YFVector<T>::clear(){
    int i = 0;
    while (i < _size){
        arr[i].~T();
        i++;
    }
    _size = 0;
}

// Insert item at Iterator
template<typename T>
inline void YFVector<T>::insert(iterator iter, T const &val) {
        YFVector tmp;
        for (auto it1 = begin(); it1 != iter; ++it1) {
            tmp.push_back(*it1);
        }

        tmp.push_back(val);

        for (auto it1 = iter; it1 != end();  ++it1) {
            tmp.push_back(*it1);
        }

        swap(*this, tmp);
    }


//***********************************ITERATORS**************************************************

/////////////////////////Class Iterator////////////////////////////////

template<class T>
class YFVector<T>::iterator{
private:
    T* _curr;

public:
    // Parametrized constructor(&_data)
    inline explicit iterator(T* _data)
        :_curr(_data){}

    // prefix ++
    inline iterator& operator++(){
        _curr++;
        return *this;
    }

    // Overloaded operator +=
    inline iterator& operator+=(size_t val){
        _curr += val;
        return *this;
    }

    // Overloaded operator +
    inline iterator operator+(size_t val){
         iterator tmp = iterator(*this);
         tmp += val;
         return tmp;
     }

    // prefix --
    inline iterator& operator--(){
        _curr--;
        return *this;
    }

    // Comparison operator <
    inline bool operator<(iterator const &other) const{
            return _curr < other._curr;
    }

    // Comparison operators >
    inline bool operator>(iterator const &other) const{
        return _curr > other._curr;
    }

    // Comparison operator ==
    inline bool operator==(const iterator& anotherIter) const{
        return *_curr == *anotherIter._curr;
    }

    // Comparison operator !=
    inline bool operator!=(const iterator& anotherIter) const{
        return *_curr != *anotherIter._curr;
    }
    // Dereferencing operator *
    inline T& operator*(){
        return *_curr;
    }
};

// begin Iterator
template<typename T>
inline typename YFVector<T>::iterator YFVector<T>::begin(){
    return iterator(&arr[0]);
}

// end iterator
template<typename T>
inline typename YFVector<T>::iterator YFVector<T>::end(){
    return begin() + _size;
}

//******************************COMPARISON OPERATIONS*******************************************

// operator==
template<typename T>
inline bool YFVector<T>::operator== (const YFVector<T>& v) const {
    if( _size == v.size()){
        int i = 0;
        while (arr[i] == v.arr[i] && i < _size){
            i++;
        }
        if (i == _size)
            return true;
        return false;
    }
    return false;
}

// operator<
template<typename T>
inline bool YFVector<T>::operator<(const YFVector<T>& v) const{
    if(arr[0] < v.arr[0])
        return true;
       return false;
}

//**********************************CAPACITY OPERATIONS***********************************************

// size function
template<typename T>
inline int YFVector<T>::size() const{
    return _size;
}

// capacity function
template<typename T>
inline int YFVector<T>::capacity() const{
    return _capacity;
}

// empty function
template<typename T>
inline bool YFVector<T>::empty() const{
    if(_size == 0)
        return true;
    return false;
}

//*************************************FRIEND OUT STREAM***************************************
template<typename T>
inline int YFVector<T>::resize() {
    T* temp = new T[2 * _capacity];

    // copying old array elements to new array
    for (int i = 0; i < _capacity; i++) {
        temp[i] = arr[i];
    }

    // deleting previous array
    delete[] arr;
    _capacity *= 2;
    arr = temp;

    return _capacity;
}

// private copy data function
template<typename T>
inline void YFVector<T>::copyInternalData(const YFVector& anotherVec){
    arr = new T[anotherVec._capacity];
    _size = anotherVec._size;
    _capacity = anotherVec._capacity;

    for(int i = 0; i < anotherVec._size; ++i){
            arr[i] = anotherVec.arr[i];
        }
}
