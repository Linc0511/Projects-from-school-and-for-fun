//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----02 Binary Search Tree
// Due Date----February 27, 2026
//
// This is the header file for the SearchTree class. Declares the class
// structure for a binary search tree of integers using a linked node structure.
//-------------------------------------------------------------------------------

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <iostream>

class SearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertHelper(Node*& node, int val);
    void printHelper(Node* node, bool& first) const;
    Node* copyHelper(Node* node) const;
    void destroyHelper(Node* node);

public:
    SearchTree();
    SearchTree(const SearchTree& other);
    ~SearchTree();
    SearchTree& operator=(const SearchTree& other);

    void insert(int new_entry);
    void print() const;
};

#endif