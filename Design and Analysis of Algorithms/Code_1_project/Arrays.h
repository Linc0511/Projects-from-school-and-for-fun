template <typename T>
struct Set {
    T *items;
    int count;
};

template <typename T> void initialize(Set<T> &set, int max) {
    set.items = new T[max];
    set.count = 0;
}

template <typename T> void destroy(Set<T> &set) {
    delete[] set.items;
    set.items = nullptr;
    set.count = 0;
}

template <typename T> void insert(Set<T> &set, T item) {
    if (!contains(set, item)) {
        set.items[set.count++] = item;
    }
}

template <typename T> void remove(Set<T> &set,T item){
    for (int i = 0; i < set.count; ++i) {
        if (set.items[i] == item) {
            set.items[i] = set.items[--set.count];
            return;
        }
    }   
}

template <typename T> bool contains(Set<T> &set,T item){
    int i=0;
    while(i < set.count) {
        if(set.items[i] == item) {
            return true;
        }
        i++;
    }
    return false;
}

template <typename T> int size(Set<T> &set) {
    return set.count;
}
