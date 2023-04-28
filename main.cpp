
#include "ArrayList.cpp"
#include "SingleLinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include <iostream>
using namespace std;


int main() {
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
    list.swap(1, 5);
    cout << "After swapping 0, 7:\n";
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

    return 0;
}
