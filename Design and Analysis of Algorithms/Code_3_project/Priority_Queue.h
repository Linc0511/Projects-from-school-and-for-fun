#include <iostream>
#include <cassert>

template <typename R, typename V>
struct PriorityQueue {
    R *rank;
    V *value;
    int values;
    int size;
};

template <typename R, typename V>
void initialize(PriorityQueue<R, V> &pq, int size) {
    pq.rank = new R[size];
    pq.value = new V[size];
    pq.values = 0;
    pq.size = size;
}

template <typename R, typename V>
void destroy(PriorityQueue<R, V> &pq) {
    delete[] pq.rank;
    delete[] pq.value;
    pq.values = 0;
    pq.size = 0;
}

template <typename R, typename V>
void swap(PriorityQueue<R, V> &pq, int i, int j) {
    std::swap(pq.rank[i], pq.rank[j]);
    std::swap(pq.value[i], pq.value[j]);
}

template <typename R, typename V>
void heapify_up(PriorityQueue<R, V> &pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq.rank[index] > pq.rank[parent]) {
            swap(pq, index, parent);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename R, typename V>
void insert(PriorityQueue<R, V> &pq, R rank, V value) {
    if (pq.values == pq.size) {
        // Double the size of the queue
        pq.size *= 2;
        R *newRank = new R[pq.size];
        V *newValue = new V[pq.size];
        for (int i = 0; i < pq.values; ++i) {
            newRank[i] = pq.rank[i];
            newValue[i] = pq.value[i];
        }
        delete[] pq.rank;
        delete[] pq.value;
        pq.rank = newRank;
        pq.value = newValue;
    }

    pq.rank[pq.values] = rank;
    pq.value[pq.values] = value;
    heapify_up(pq, pq.values);
    pq.values++;
}


template <typename R, typename V>
void heapify_down(PriorityQueue<R, V> &pq, int index) {
    while (2 * index + 1 < pq.values) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int max_child = left_child;

        if (right_child < pq.values && pq.rank[right_child] > pq.rank[left_child]) {
            max_child = right_child;
        }

        if (pq.rank[index] < pq.rank[max_child]) {
            swap(pq, index, max_child);
            index = max_child;
        } else {
            break;
        }
    }
}

template <typename R, typename V>
V pop(PriorityQueue<R, V> &pq) {
    assert(pq.values > 0);

    V result = pq.value[0];
    pq.rank[0] = pq.rank[pq.values - 1];
    pq.value[0] = pq.value[pq.values - 1];
    pq.values--;

    heapify_down(pq, 0);

    return result;
}

template <typename R, typename V>
int size(PriorityQueue<R, V> &pq) {
    return pq.values;
}
