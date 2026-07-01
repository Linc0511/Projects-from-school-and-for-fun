#include <iostream>

template <typename T>
struct Node {
    T value;
    Node *left;
    Node *right;
};

template <typename T>
struct Set {
    Node<T> *root;
};

template <typename T>
void destroyHelper(Node<T>* node) {
    if (node) {
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

template <typename T>
void initialize(Set<T> &set) {
    set.root = nullptr;
}

template <typename T>
void destroy(Set<T> &set) {
    destroyHelper(set.root);
    set.root = nullptr;
}

template <typename T>
Node<T>* insertHelper(Node<T>* node, T item) {
    if (!node) {
        node = new Node<T>{item, nullptr, nullptr};
    } else if (item < node->value) {
        node->left = insertHelper(node->left, item);
    } else if (item > node->value) {
        node->right = insertHelper(node->right, item);
    }
    return node;
}

template <typename T>
void insert(Set<T> &set, T item) {
    set.root = insertHelper(set.root, item);
}

template <typename T>
Node<T>* removeHelper(Node<T>* node, T item) {
    if (!node) {
        return nullptr;
    }

    if (item < node->value) {
        node->left = removeHelper(node->left, item);
    } else if (item > node->value) {
        node->right = removeHelper(node->right, item);
    } else {
        if (!node->left) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* temp = node->right;
        while (temp->left) {
            temp = temp->left;
        }

        node->value = temp->value;
        node->right = removeHelper(node->right, temp->value);
    }

    return node;
}

template <typename T>
void remove(Set<T> &set, T item) {
    set.root = removeHelper(set.root, item);
}

template <typename T>
bool containsHelper(Node<T>* node, T item) {
    if (!node) {
        return false;
    }

    if (item < node->value) {
        return containsHelper(node->left, item);
    } else if (item > node->value) {
        return containsHelper(node->right, item);
    } else {
        return true;
    }
}

template <typename T>
bool contains(Set<T> &set, T item) {
    return containsHelper(set.root, item);
}

template <typename T>
int sizeHelper(Node<T>* node) {
    if (!node) {
        return 0;
    }

    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}

template <typename T>
int size(Set<T> &set) {
    return sizeHelper(set.root);
}
