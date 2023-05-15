#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H


#include "iostream"
#include "Student.h"

using namespace std;

class BSTNode{
public:
    Student student;
    BSTNode* left{}, *right{};
    explicit BSTNode()= default;
    explicit BSTNode(Student student){
        this->student = std::move(student);
        left = right = nullptr;
    }
};

class BST {
private:
    BSTNode *root;
    int treeSize{};
public:
    BST();
    int size() const;
    bool found(int id);
    void search(int id);
    void insert(const Student &student);
    void printInorder(BSTNode *node);
    void print();
    void remove(int id);
};

#endif //BINARY_SEARCH_TREE_BST_H