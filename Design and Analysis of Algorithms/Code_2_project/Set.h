#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
struct Set {
    Node<T>* head;
};

template <typename T>
void initialize(Set<T>& set) {
    set.head = nullptr;
}

template <typename T>
void destroy(Set<T>& set) {
    while (set.head) {
        Node<T>* temp = set.head;
        set.head = set.head->next;
        delete temp;
    }
}

template <typename T>
void insert(Set<T>& set, T item) {

    if (!contains(set, item)) {
        Node<T>* newNode = new Node<T>{item, set.head};
        set.head = newNode;
    }
}

template <typename T>
void remove(Set<T>& set, T item) {
    if(contains(set, item))
    {
        Node<T>* temp = set.head;
        set.head = temp->next;
        delete temp;
    }
}

template <typename T>
bool contains(Set<T>& set, T item) {
    Node<T>* current = set.head;
    Node<T>* prev = nullptr;

    while (current && current->value != item) {
        prev = current;
        current = current->next;
    }

    if (current) {
        // Move the found item to the front for optimization
        if (prev) {
            prev->next = current->next;
            current->next = set.head;
            set.head = current;
        }
        return true;
    } else {
        // Value not found
        return false;
    }
}

template <typename T>
int size(Set<T>& set) {
    int count = 0;
    Node<T>* current = set.head;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}


