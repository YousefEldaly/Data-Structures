#include <iostream>
#include <fstream>
#include <map>
#include "BST.h"
#include "AVL.h"
using namespace std;


int main() {
    // create a map on departments
    map<string,int> departments;

    // create tree
    auto bst = new BST();
    auto avl = new AVL();


    // read file
    ifstream myFile(R"(D:\Study\Level 2\Data_Stuctures\Assignments\Assignment3\Trees\Students.txt)");
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
                // Min Heap insertion
                // Max Heap insertion
                avl->insert(stud);
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
        int option;
        cin >> option;
        switch (option) {
            case 1: {
                // first set departments
                // IMPORTANT FOR ALL CASES
                bst->setDepartments(departments);
                bst->displayMenu();
                break;
            }
            case 2:
                avl->setDepartments(departments);
                avl->displayMenu();
                break;

            case 5:
                flag = false;
                break;
        }
    }

}