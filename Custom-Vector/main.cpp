#include <bits/stdc++.h>
#include "YFVector.cpp"
#include "exceptions.h"

using namespace std;
int main(){
    int test[5] = {1, 2, 3, 4, 5};
    YFVector<int> v4(test, sizeof(test)/sizeof(test[0]));

    cout << "v4 after passing an array\n";
    cout << v4 ;
    cout << "\n---------------------------------------------\n";


    YFVector<int> v5(v4);
    cout << "v5 initialized by a copy constructor of v4:\n";
    cout << v5 << endl;
    cout << "\nv5 size = " << v5.size();
    cout << "\nv5 capacity = " << v5.capacity() << "\n";
    cout << "------------------------------------------------\n";

    YFVector<int> v6;
    v6 = v5;
    cout << "v6 after copy assignment of v5:\n";
    cout << v6;
    cout << "\nv6 size = " << v6.size();
    cout << "\nv6 capacity = " << v6.capacity() << "\n";
    cout << "V5 is " << ((v5.empty()) ? "empty": "NOT empty") << endl;
    cout << v5 << endl;
    cout << "------------------------------------------------\n";

    YFVector<int> v7;
    v7 = move(v6);
    cout << "v7 after move assignment: \n";
    cout << v7 << endl;
    cout << "V6 is " << ((v6.empty()) ? "empty": "NOT empty") << endl;
    cout << "\nv7 size = " << v7.size();
    cout << "\nv7 capacity = " << v7.capacity() << "\n";
    cout << "------------------------------------------------\n";

//////////////////////////////////////////////////////////////////////////////////////////////////
    YFVector<char> v1(4);
    YFVector<int> v2;
    YFVector<int> v3(4);

    v1.push_back('f');
    v1.push_back('a');
    v1.push_back('t');
    v1.push_back('m');
    // More capacity *2 to push another element
    v1.push_back('a');

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);

    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);

    cout << "Compare between v2 == v3 : "<< ((v2 == v3) ? "True" : "False") << endl;

    YFVector<int> vec4(3);
    YFVector<int> vec5(3);

    vec4.push_back(8);
    vec4.push_back(4);
    vec4.push_back(2);

    vec5.push_back(6);
    vec5.push_back(4);
    vec5.push_back(2);
    cout << "-------------------------------------------"<< endl;
    cout << "Is v4 < 45 ?" <<((v4 < v5) ? " Yes": " NO" ) << endl;
    cout << "-------------------------------------------" << endl;


    try{
        cout << "V2[2]Operator Before: " << v2[2] << endl;
        v2[2] = 4;
        cout << "V2[2]Operator After: " << v2[2] << endl;
    }
    catch(outOfRange& outofrange){
        cout << "Exception occurred: " << outofrange.what() << endl;
    }


    cout << "-------------------------------------------"<< endl;
    cout << "V1 size: " << v1.size() << endl;
    cout << "V1 capacity: " << v1.capacity() << endl;
    cout << "V2 size: " << v2.size() << endl;
    cout << "V2 capacity: " << v2.capacity() << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V1 elements: "<< v1 << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V2 elements: "<< v2 << endl;

    int x;
    char c;
    try {
        x = v2.pop_back();
        c = v1.pop_back();
    }
    catch(noPop& nopop){
        cout << "Exception occurred: " << nopop.what() << endl;
    }


    cout << "-------------------------------------------"<< endl;
    cout << "After deleting last element" << endl;
    cout << "Last elements are deleted:" << endl;

    cout << x << " " << c << endl;
    // V2 elements after pop_back
    cout << "V2 elements: " << v2 << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V1 size: " << v1.size() << endl;
    cout << "V1 capacity: " << v1.capacity() << endl;
    cout << "V2 size: " << v2.size() << endl;
    cout << "V2 capacity: " << v2.capacity() << endl;
    cout << "-------------------------------------------"<< endl;

    // Clear test
    v1.clear();
    cout << "V1 is " << ((v1.empty()) ? "empty": "NOT empty") << endl;
    cout << "----------------------------------------\n";

    /////////////// Test Iterators ///////////////////
    try {
        v3.erase(v3.begin());
        cout << "v3 after erase its begin position: " << endl;
        cout << v3 << endl;
    }
    catch(outOfRange& outofrange){
        cout << "Exception occurred: " << outofrange.what() << endl;
    }

    v3.erase(v3.begin(), v3.end());
    cout << "v3 is " << ((v3.empty()) ? "empty" : "NOT empty") << endl;

    v2.insert(v2.begin(), 5);
    cout << "Inserting 5 at begin of v2: " << v2 << endl;
    cout << "----------------------------------------\n";
    ///////////  Test Exception ////////////////////////

    try {
        v1.erase(v1.begin(), v1.end() + 2);
    }
    catch(outOfRange& outofrange) {
        cout << "Exception occurred: " << outofrange.what() << endl;

    }

    try {
        v2[1000] = 5;
    }
    catch(outOfRange& outofrange) {
        cout << "Exception occurred: " << outofrange.what() << endl;

    }

    try {
        v2.pop_back();
        v2.pop_back();
        v2.pop_back();
        v2.pop_back();
        v2.pop_back();
        // Exception
        v2.pop_back();
    }

    catch(noPop& nopop){
        cout << "Exception occurred: " << nopop.what() << endl;
    }

    return 0;
}
