template <typename T>
struct List 
{
    T   data[100];
    int count = 0;

    struct Iterator 
    {
        List * list;
        int index;

        operator bool() const 
        {
            return index >=0 && index < list->count;
        }

        Iterator & operator++() 
        {
            index++;
            return *this;
        }

        Iterator operator++(int) 
        {
            Iterator t = *this;
            index++;
            return t;
        }

        Iterator & operator--() {
            index--;
            return *this;
        }

        Iterator operator--(int) 
        {
            Iterator t = *this;
            index--;
            return t;
        }

        T & operator*() 
        {
            return list->data[index];
        }

        T * operator->() 
        {
            return &list->data[index];
        }

        void insert(T value) 
        {
            for (int i=list->count-1; i>=index; i--)
            list->data[i+1] = list->data[i];
            list->count++;
            list->data[index] = value;
        }

        void remove() 
        {
            for (int i=index; i<list->count-1; i++)
                list->data[i] = list->data[i+1];
            list->count--;
        }
    };

    bool isEmpty() 
    {
        return count == 0;
    }

    Iterator getHead() 
    {
        return Iterator{this,0};
    }

    Iterator getTail() 
    {
        return Iterator{this,count-1};
    }

    void prepend(T value) 
    {
        Iterator{this,0}.insert(value);
    }

    void append(const T &value) 
    {
        Iterator{this,count}.insert(value);
    }
};
