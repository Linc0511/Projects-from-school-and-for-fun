//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----02 Binary Search Tree
// Due Date----February 27, 2026
//
// This is the implementation file for the SearchTree class.
//-------------------------------------------------------------------------------

#include "SearchTree.h"

//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------
SearchTree::SearchTree() : root(nullptr) {}

//-------------------------------------------------------------------------------
// Copy Constructor
//
// Creates a deep copy of the tree by copying the nodes.
//-------------------------------------------------------------------------------
SearchTree::SearchTree(const SearchTree& other) {
    std::cout << "Hello from the copy constructor!\n";
    root = copyHelper(other.root);
}

//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
SearchTree::~SearchTree() {
    std::cout << "Hello from the destructor!\n";
    destroyHelper(root);
}

//-------------------------------------------------------------------------------
// operator=
//
// Overloaded =, or assignment operator, correctly delets the tree and frees
// memory, then creates a deep copy of the right hand operator tree.
//-------------------------------------------------------------------------------
SearchTree& SearchTree::operator=(const SearchTree& other) {
    if (this != &other) {
        std::cout << "Hello from the assignmant operator!\n";
        destroyHelper(root);
        root = copyHelper(other.root);
    }
    return *this;
}

//-------------------------------------------------------------------------------
// insert
//
// Inserts a new value into the tree following BST rules.
//-------------------------------------------------------------------------------
void SearchTree::insert(int new_entry) {
    insertHelper(root, new_entry);
}

//-------------------------------------------------------------------------------
// print
//
// Outputs all tree values to the screen on one line separated by commas
// using in-order traversal.
//-------------------------------------------------------------------------------
void SearchTree::print() const {
    bool first = true;
    printHelper(root, first);
    std::cout << std::endl;
}

//-------------------------------------------------------------------------------
// insertHelper
//
// Recursively finds the correct position and inserts a new node into the
// tree maintaining BST ordering.
//-------------------------------------------------------------------------------
void SearchTree::insertHelper(Node*& node, int val) {
    if (node == nullptr) {
        node = new Node(val);
    } else if (val < node->data) {
        insertHelper(node->left, val);
    } else {
        insertHelper(node->right, val);
    }
}

//-------------------------------------------------------------------------------
// printHelper
//
// Recursively performs in-order traversal printing each value with a boolean to 
// ensure the correct formatting.
//-------------------------------------------------------------------------------
void SearchTree::printHelper(Node* node, bool& first) const {
    if (node == nullptr) return;
    printHelper(node->left, first);
    if (!first) std::cout << ", ";
    std::cout << node->data;
    first = false;
    printHelper(node->right, first);
}

//-------------------------------------------------------------------------------
// copyHelper
//
// Recursively creates a deep copy of a subtree and returns a pointer to
// the new subtree root.
//-------------------------------------------------------------------------------
SearchTree::Node* SearchTree::copyHelper(Node* node) const {
    std::cout << "Hello from the copy helper!\n";
    if (node == nullptr) return nullptr;
    Node* newNode = new Node(node->data);
    newNode->left = copyHelper(node->left);
    newNode->right = copyHelper(node->right);
    return newNode;
}

//-------------------------------------------------------------------------------
// destroyHelper
//
// Recursively deletes all nodes in a subtree using post-order traversal
// to free all allocated memory.
//-------------------------------------------------------------------------------
void SearchTree::destroyHelper(Node* node) {
    std::cout << "Hello from the destructor helper!\n";
    if (node == nullptr) return;
    destroyHelper(node->left);
    destroyHelper(node->right);
    delete node;
}