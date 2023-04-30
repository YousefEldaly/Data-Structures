
#include "ArrayList.cpp"
#include "SingleLinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "Stack.cpp"
#include "CircularLinkedList.cpp"
#include "CombineNodesBetweenZeros.cpp"
#include "Queue.cpp"
#include <iostream>
#include "StackProblem.cpp"
#include <String.h>
using namespace std;

int main()
{
    /*ArrayList<int> l1;
    l1.insert(5);
    l1.insert(5);
    l1.insert(5);
    l1.insert(5);
    l1.print();

    SingleLinkedList<int> list;
    list.insertAtHead(90);
    list.insertAtHead(90);
    list.insertAtTail(40);
    list.insertAtTail(30);
    list.insertAt(50, 2);
    list.insertAtTail(30);
    list.insertAtTail(30);
    list.print();
    cout << endl;
    list.swap(0, 6);
    cout << "list after swapping 0, 6: \n";
    list.print();
    cout << endl;
    list.removeAtHead();
    cout << "After removing head: \n";
    list.print();
    cout << endl;
    list.removeAtTail();
    cout << "After removing tail: \n";
    list.print();
    cout << endl;
    cout << "After removing at 3: \n";
    list.removeAt(3);
    list.print();
    cout << endl;
    cout << "List size: " << list.listSize();
    cout << endl;
    cout << "Retrieving at 2: " << list.retrieveAt(2) << endl;
    cout << "replacing at 2 by 100...\n";
    list.replaceAt(100, 2);
    cout << "Retrieving at 2: " << list.retrieveAt(2) << endl;
    cout << "checking if 200 exists: ";
    cout << list.isExist(200) << endl;
    cout << "checking if item at 1 equals 50: ";
    cout << list.isItemAtEqual(50, 1) << endl;
    cout << "printing list\n";
    list.print();
    cout << endl;
    list.reverse();
    cout << "After reversing:\n";
    list.print();
    cout << endl;
    list.clear();
    cout << "after Clearing...\n";
    list.print();
*/

    // DoublyLinkedList<int> list;
    // list.insertAtHead(90);
    // list.insertAtHead(90);
    // list.print();
    // cout << endl;
    // list.insertAtTail(40);
    // list.insertAtTail(30);
    // list.print();
    // cout << endl;
    // list.insertAtTail(30);
    // list.insertAtTail(30);
    // list.print();
    // cout << endl;
    // list.insertAt(50, 2);
    // list.print();
    // cout << endl;
    // list.swap(1, 5);
    // cout << "After swapping 0, 7:\n";
    // list.print();
    // cout << endl;
    // cout << "After removing at head:\n";
    // list.removeAtHead();
    // list.print();
    // cout << endl;
    // cout << "After Removing at tail:\n";
    // list.removeAtTail();
    // list.print();
    // cout << endl;
    // cout << "after removing at 3:\n";
    // list.removeAt(3);
    // list.print();
    // cout << endl;
    // cout << "List size: " << list.listSize() << endl;
    // cout << endl;
    // cout << "item at index 2: " << list.retrieveAt(2) << endl;
    // list.replaceAt(100, 2);
    // cout << "item at 2 is replaced, new at 2: " << list.retrieveAt(2) << endl;
    // cout << "is 200 Exits? " << list.isExist(200) << endl;
    // cout << "is item at index 1 = 50? " << list.isItemAtEqual(50, 1) << endl;
    // cout << "printing the list...\n";
    // list.print();
    // cout << endl;
    // list.reverse();
    // cout << "printing after reverse:\n";
    // list.print();
    // cout << endl;
    // cout << "printing after clearing:\n";
    // list.clear();
    // list.print();

    /*
     *
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();  // Output: Queue: 1 2 3
    q.dequeue();
    q.print();  // Output: Queue: 2 3
    cout << q.first() << endl;  // Output: 2
    cout << q.isEmpty() << endl;  // Output: 0 (false)
    cout << q.queueSize() << endl;  // Output: 2
    q.clear();
    q.print();  // Output: Queue is empty!
     *
     * */
/*
    Stack<int> stack;
    stack.push(40);
    stack.push(30);
    stack.push(60);
    stack.push(50);
    stack.push(70);
    cout << "stack: ";
    stack.print();
    cout << endl;
    cout << "the top of the stack: " << stack.top();
    cout << endl;
    cout << "check if stack is empty: " << stack.isEmpty() << endl;
    cout << "after poping the first element: ";
    stack.pop();
    stack.print();
    cout << endl;
    cout << "the size of the stack: " << stack.stackSize() << endl;
    cout << "the element on the top: " << stack.top() << endl;
    cout << "after clearing the stack: ";
    stack.clear();
    stack.print();
    cout << endl;
    cout << "check if stack is empty: " << stack.isEmpty() << endl;
*/
/*
    DoublyLinkedList<int> list;
    list.insertAtHead(90);
    list.insertAtHead(90);
    list.print();
    cout << endl;
    list.insertAtTail(40);
    list.insertAtTail(30);
    list.print();
    cout << endl;
    list.insertAtTail(30);
    list.insertAtTail(30);
    list.print();
    cout << endl;
    list.insertAt(50, 2);
    list.print();
    cout << endl;
    list.swap(0, 6);
    cout << "After swapping 0, 6:\n";
    list.print();
    cout << endl;
    cout << "After removing at head:\n";
    list.removeAtHead();
    list.print();
    cout << endl;
    cout << "After Removing at tail:\n";
    list.removeAtTail();
    list.print();
    cout << endl;
    cout << "after removing at 3:\n";
    list.removeAt(3);
    list.print();
    cout << endl;
    cout << "List size: " << list.listSize() << endl;
    cout << endl;
    cout << "item at index 2: " << list.retrieveAt(2) << endl;
    list.replaceAt(100, 2);
    cout << "item at 2 is replaced, new at 2: " << list.retrieveAt(2) << endl;
    cout << "is 200 Exits? " << list.isExist(200) << endl;
    cout << "is item at index 1 = 50? " << list.isItemAtEqual(50, 1) << endl;
    cout << "printing the list...\n";
    list.print();
    cout << endl;
    list.reverse();
    cout << "printing after reverse:\n";
    list.print();
    cout << endl;
    cout << "printing after clearing:\n";
    list.clear();
    list.print();
*/
/*
    CircularLinkedList<int> list;
    list.insertAtHead(90);
    list.insertAtHead(90);
    list.print();
    cout << endl;
    list.insertAtTail(40);
    list.insertAtTail(30);
    list.print();
    cout << endl;
    list.insertAtTail(30);
    list.insertAtTail(30);
    list.print();
    cout << endl;
    list.insertAt(50, 2);
    list.print();
    cout << endl;
    list.swap(1, 6);
    cout << "After swapping 1, 6:\n";
    list.print();
    cout << endl;
    cout << "After removing at head:\n";
    list.removeAtHead();
    list.print();
    cout << endl;
    cout << "After Removing at tail:\n";
    list.removeAtTail();
    list.print();
    cout << endl;
    cout << "after removing at 3:\n";
    list.removeAt(3);
    list.print();
    cout << endl;
    cout << "List size: " << list.listSize() << endl;
    cout << endl;
    cout << "item at index 2: " << list.retrieveAt(2) << endl;
    list.replaceAt(100, 2);
    cout << "item at 2 is replaced, new at 2: " << list.retrieveAt(2) << endl;
    cout << "is 200 Exits? " << list.isExist(200) << endl;
    cout << "is item at index 1 = 50? " << list.isItemAtEqual(50, 1) << endl;
    cout << "printing the list...\n";
    list.print();
    cout << endl;
    list.reverse();
    cout << "printing after reverse:\n";
    list.print();
    cout << endl;
    cout << "printing in reverse:\n";
    list.printReverse();
    cout << endl;
    cout << "printing after clearing:\n";
    list.clear();
    list.print();
*/

/*    SingleLinkedList<int> list;
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(3);
    list.insertAtTail(0);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(0);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(0);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(0);


    list.print();
    cout << endl;
    SingleLinkedList<int> combined_list = CombineNodesBetweenZeros(list);
    combined_list.print();

//----------------------------------------------Testing Queue Implementiation--------------------------------------------

/*
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print(); // should print 10 20 30 40
    std::cout << "Queue size: " << q.queueSize() << std::endl; // should print 4
    std::cout << "First element: " << q.first() << std::endl; // should print 10
    std::cout << "Dequeued element: " << q.dequeue() << std::endl; // should print 10
    q.print(); // should print 20 30 40
    std::cout << "Queue size: " << q.queueSize() << std::endl; // should print 3
    q.clear();
    std::cout << "Queue size after clear: " << q.queueSize() << std::endl; // should print 0
    return 0;
  */

    //----------------------------------------------(Problem) Testing Stack Implementiation using Queue--------------------------------------------


    /*
    StackProblem<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.pop() << std::endl; // should print 30
    std::cout << s.pop() << std::endl; // should print 20
    std::cout << s.pop() << std::endl; // should print 10

    std::cout << s.isEmpty() << std::endl; // should print 1 (true)

    s.push(40);

    std::cout << s.isEmpty() << std::endl; // should print 0 (false)

    s.clear();

    std::cout << s.isEmpty() << std::endl; // should print 1 (true)

    return 0;
*/
    //----------------------------------------------(Problem) Testing sorting Queue--------------------------------------------
    Queue<int> q1;
    q1.enqueue(3);
    q1.enqueue(15);
    q1.enqueue(2);
    q1.enqueue(4);

    cout << "Before sorting:\n";
    q1.print(); // should print: 3 15 2 4
    selectionSort(q1);

    cout << "\nAfter sorting:\n";
    q1.print(); // should print: 2 3 4 15
}
