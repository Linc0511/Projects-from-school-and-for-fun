#include <iostream>
#include <cassert>

template <typename K, typename V>
struct Node {
    Node<K, V> *next;
    K key;
    V value;
};

template <typename K, typename V>
struct Map {
    Node<K, V> **table;
    int keys;
    int size;
};

template <typename K, typename V>
void initialize(Map<K, V> &map) { //c
    map.table = new Node<K, V> *[10](); // Initialize to null pointers
    map.keys = 0;
    map.size = 10;
}

template <typename K, typename V>
void destroy(Map<K, V> &map) { //c
    for (int i = 0; i < map.size; ++i) {
        Node<K, V> *current = map.table[i];
        while (current != nullptr) {
            Node<K, V> *next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] map.table;
}

template <typename K>
int hashKey(K key, int size) { //l
    // Modify the hash function according to your needs
    return std::hash<K>{}(key) % size;
}

template <typename K, typename V>
void update(Map<K, V> &map, K key, V value) { //l
    int index = hashKey(key, map.size);

    Node<K, V> *current = map.table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Key not found, insert a new node
    Node<K, V> *newNode = new Node<K, V>{nullptr, key, value};
    newNode->next = map.table[index];
    map.table[index] = newNode;
    ++map.keys;

    // Check and expand the table if needed
    if (map.keys > map.size / 2) {
        // Double the size of the table
        int newSize = map.size * 2;
        Node<K, V> **newTable = new Node<K, V> *[newSize]();

        // Rehash and move existing elements to the new table
        for (int i = 0; i < map.size; ++i) {
            current = map.table[i];
            while (current != nullptr) {
                Node<K, V> *next = current->next;
                int newIndex = hashKey(current->key, newSize);
                current->next = newTable[newIndex];
                newTable[newIndex] = current;
                current = next;
            }
        }

        // Clean up the old table
        delete[] map.table;

        // Update the map's size and table
        map.size = newSize;
        map.table = newTable;
    }
}

template <typename K, typename V>
void remove(Map<K, V> &map, K key) { //l
    int index = hashKey(key, map.size);

    Node<K, V> *current = map.table[index];
    Node<K, V> *prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                map.table[index] = current->next;
            }
            delete current;
            --map.keys;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename K, typename V>
bool contains(Map<K, V> &map, K key) { //c
    int index = hashKey(key, map.size);

    Node<K, V> *current = map.table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}

template <typename K, typename V>
V lookup(Map<K, V> &map, K key) { //l
    int index = hashKey(key, map.size);

    Node<K, V> *current = map.table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // Key not found, you might want to handle this differently based on your requirements
    throw std::out_of_range("Key not found in the map");
}

template <typename K, typename V>
int size(Map<K, V> &map) {
    return map.keys;
}


