#include <iostream>

// Node struct for the AVL Tree
template <typename T>
struct Node {
    T       value;
    int     height;
    Node *  left;
    Node *  right;
};

// Set struct that represents the AVL Tree
template <typename T>
struct Set {
    Node<T> *root;
};

// Creates the set used for the AVL Tree
template <typename T>
void initialize(Set<T> &set) {
    set.root = nullptr;
}

// Delete the node and the children
template <typename T>
void destroyHelper(Node<T> *node) {
    // Base Case: If the current node is present, destroy the children and delete the node.
    if (node) {
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

// Deletes all the nodes in the tree and sets the root node to null.
template <typename T>
void destroy(Set<T> &set) {
    destroyHelper(set.root);
    set.root = nullptr;
}

// Finds the current height for the tree
template <typename T>
int getHeight(Node<T> *node) {
    // Base Case: if the node does not have a null value, return the height.
    if (node != nullptr) {
        return node->height;
    }
    // If the node has a null value, return -1.
    else if (node == nullptr) {
        return -1;
    }
    // If the node is a duplicate, return 0.
    else {
        return 0;
    }
}

// Finds the balance of the tree using the height of the left and right side of the tree.
template <typename T>
int getBalanceFactor(Node<T> *node) {
    return getHeight(node->left) - getHeight(node->right);
}

// Updates the height whenever a node is inserted.
template <typename T>
void updateHeight(Node<T> *node) {
    // Base Case: if the node has a value in it.
    if (node != nullptr) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

// Creates a template to rotate the AVL Tree right
template <typename T>
Node<T> *rotateRight(Node<T> *y) {
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}


// Creates a template named Node to rotate the AVL Tree left.
template <typename T>
Node<T> *rotateLeft(Node<T> *x) {
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Creates a template named Node that has infrastructure to maintain the tree balance.
template <typename T>
Node<T> *insertHelper(Node<T> *node, T item) {
    // Base Case: if the node is not null then make a new node and return it.
    if (!node) {
        Node<T> *newNode = new Node<T>{item, 0, nullptr, nullptr};
        return newNode;
    }

    if (item < node->value) {
        // If item is less the the current node's value, make a recursive call on the left child
        node->left = insertHelper(node->left, item);
    } else if (item > node->value) {
        // If item is greater the the current node's value, make a recursive call on the right child
        node->right = insertHelper(node->right, item);
    } else {
        // If the node is equal then just return it.
        return node;
    }

    int balance = getBalanceFactor(node);

    // If the balance is greater than 1 and the item is less than the left child,
    //then call rotate right and return the value.
    if (balance > 1 && item < node->left->value) {
        return rotateRight(node);
    }
    // If the balance is less than than 1 and the item is greater than the right child,
    //then call rotate left and return the value.
    if (balance < -1 && item > node->right->value) {
        return rotateLeft(node);
    }
    // If the balance is greater than 1 and the item is greater than the left child,
    //then set left child equal to the value of rotate left
    // and call rotate right and return the value.
    if (balance > 1 && item > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // If the balance is less than 1 and the item is less than the left child,
    //then set right child equal to the value of rotate right
    // and call rotate left and return the value.
    if (balance < -1 && item < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    updateHeight(node);
    return node;
}

// Inserts a new node and calls insert helper to keep the tree balanced.
template <typename T>
void insert(Set<T> &set, T item) {
    set.root = insertHelper(set.root, item);
}

// Finds the node with the smallest value by traversing the left side of the tree.
template <typename T>
Node<T> *findMinValueNode(Node<T> *node) {
    Node<T> *current = node;
    while (current->left) {
        // Loop invariant: the current node has a left child.
        current = current->left;
    }
    return current;
}

// Creates the infrastructure for the delete node function.
template <typename T>
Node<T> *deleteNode(Node<T> *root, T item) {
    // Base Case: If the node is not the root, return the root.
    if (!root) {
        return root;
    }

    // If the item to delete is less than the root, then call deleteNode and go to the next left node.
    if (item < root->value) {
        root->left = deleteNode(root->left, item);
    } else if (item > root->value) {
        // If the item is greater than the root then call deleteNode and go to the next right node.
        root->right = deleteNode(root->right, item);
    } else {
        // If the node has no child, then store the value of the right or left child based on the parent being null or not.  
        if (!root->left || !root->right) {
            Node<T> *temp = root->left ? root->left : root->right;


            // If there is no child node, then store the root in temp and make the root a null pointer.
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                // If there is a child then copy the contents into temp.
                *root = *temp;
            }


            delete temp;
        } else {
            // If the node is equal then get the inorder successor on the right and move that node up the tree,
            //and then delete the successor.
            Node<T> *temp = findMinValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    // If the tree had only one node then return the root
    if (!root) {
        return root;
    }

    updateHeight(root);
    int balance = getBalanceFactor(root);

    // If the balance is greater than 1 and the left balance factor is greater than or equal to 0,
    //then call rotate right and return the value.
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }
    // If the balance is greater than 1 and the left balance factor is less than 0,
    //then call rotate right and return the value.
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    // If the balance is less than -1 and the right balance factor is greater than or equal to 0,
    //then call rotate left and return the value.
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }
    // If the balance is less than -1 and the right balance factor is greater than 0,
    //then call rotate left and return the value.
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

// remove the node by calling deleteNode
template <typename T>
void remove(Set<T> &set, T item) {
    set.root = deleteNode(set.root, item);
}

// Creates the infrastructure for contains to see if a value is in the set.
template <typename T>
bool containsHelper(Node<T> *node, T item) {
    // Base Case: if the pointer to the node is null, then return false.
    if (!node) {
        return false;
    }


    // If the item is less than the current node then go to the left, recursively call contains helper, and return that value.
    if (item < node->value) {
        return containsHelper(node->left, item);
    } else if (item > node->value) {
        // If the item is greater than the current node then go to the right, recursively call contains helper, and return that value.
        return containsHelper(node->right, item);
    } else {
        // If the node is equal than the value is in the set
        return true;
    }
}

// Checks if the node is in the set and returns true or false
template <typename T>
bool contains(Set<T> &set, T item) {
    return containsHelper(set.root, item);
}

// Calculates the size of the tree based on the number of nodes in the tree.  
template <typename T>
int sizeHelper(Node<T> *node) {
    // Base Case: if the node has a null pointer, then return 0.
    if (!node) {
        return 0;
    }
    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}

// Finds the size of the tree by calling a helper function called sizeHelper
template <typename T>
int size(Set<T> &set) {
    return sizeHelper(set.root);
}