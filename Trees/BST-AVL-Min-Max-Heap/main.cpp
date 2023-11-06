#include <iostream>
#include <fstream>
#include <map>
#include "BST.h"
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;


int main() {
    // create a map on departments
    map<string,int> departments;

    // create tree
    auto bst = new BST();
    auto max = new MaxHeap();
    auto min = new MinHeap();

    // read file
    ifstream myFile(R"(C:\Users\Omar\CLionProjects\Data_Structures_A3\Students.txt)");
    int cnt = 0;
    string line;
    Student stud;
    while (getline(myFile, line)) {
        if (!cnt) {
            cnt++;
            continue;
        }
        switch (cnt % 4) {
            case 0:
                stud.setDepartment(line);
                departments[line]++;
                // AVL insertion
                min->insert(stud);
                max->insert(stud);
                bst->insert(stud);
                break;
            case 1:
                stud.setId(stoi(line));
                break;
            case 2:
                stud.setName(line);
                break;
            case 3:
                stud.setGpa(stof(line));
                break;
        }
        cnt++;
    }
    myFile.close();



    // main menu
    bool flag = true;
    while (flag){
        cout << "Choose Data Structure:\n"
                "1. BST\n"
                "2. AVL\n"
                "3. Min Heap\n"
                "4. Max Heap\n"
                "5. Exit Program\n";
        int option; cin >> option;
        switch (option) {
            case 1: {
                // first set departments
                // IMPORTANT FOR ALL CASES
                bst->setDepartments(departments);
                bst->displayMenu();
                break;
            }
            case 3: {
                min->setDepartments(departments);
                min->displayMenu();
                break;
            }
            case 4:{
                max->setDepartments(departments);
                max->displayMenu();
                break;
            }
            case 5:
                flag = false;
                break;
        }
    }

}