//
// Created by Yusuf Aldaly on 4/28/2023.
//

#ifndef LINEAR_STRUCTURES_ARRAYLIST_H
#define LINEAR_STRUCTURES_ARRAYLIST_H



/**
 * ArrayList - Array_Based List
 * @arr: core arr to store data
 * @max_size: the list maximum size
 * @length: current list length
 */


template <typename T> class ArrayList{
private:
    T *arr;
    int curr;
    int max_size;
    int length;
    const static int DEFAULT_SIZE = 10;

public:

    ArrayList();

    /**
     * ArrayList - initializes data members max_size to given size
     *              length to zero and dynamically allocate arr[max_size]
     * @size: given size to be allocated
     */
    ArrayList(int size);

    /**
     * insert - inserts data at current position
     * @element: data to insert
     */
    void insert(T element);


    /**
     * insertAt - inserts element at given index,
     *              do appropriate shifting if required
     * @element: the data to be inserted
     * @index: index to insert data
     */
    void insertAt(T element, int index);

    /**
     *  retrieveAt - gets data from index
     */
    T retrieveAt(int index) const;


    /**
     * removeAt- removes an element form given index
     *             do appropriate shifting if needed
     * @index: index to remove data from
     */
    void removeAt(int index);

    /**
     * replaceAt - replaces data in a given index
     * @new_element: new data to insert
     * @index: index to insert into
     */
    void replaceAt(T new_element, int index);

    /**
     * isItemAtEqual - compare (if equal) given data to data at index
     * @element: data to compare
     * @index: index to compare to
     */
    bool isItemAtEqual(T element, int index) const;


    /**
     * isEmpty - checks if the list is empty
     * Return: bool
     */
    bool isEmpty() const;


    /**
     * isFull - checks if the list is full
     */
    bool isFull() const;

    /**
     * listSize - returns the list size
     * Return: length
     */
    int listSize() const;

    /**
     * maxListSize - returns the num of maximum elements a list can hold
     */
    int maxListSize() const;

    /**
     * clear - clear a list
     */
    void clear();

    /**
     * print - prints list data seperated by space
     */
    void print() const;

    void append(T element);

    /**
     * control curr position
     */
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int currPos() const;
    void moveToPos(int pos);


    /**
     * ArrayList - destructs a list
     */
    ~ArrayList();
};


#endif //LINEAR_STRUCTURES_ARRAYLIST_H
