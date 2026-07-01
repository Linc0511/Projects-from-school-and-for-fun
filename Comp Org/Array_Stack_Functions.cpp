template <typename T>
class Stack {
    T * data;
    int top;
    int maxsize;

public:
    Stack(int maxsize) {
        this->data = new T[maxsize];
        this->top = 0;
        this->maxsize = maxsize;
    }

    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        assert(top < maxsize);
        data[top++] = value;
    }

    T pop() {
        assert(top > 0);
        return data[--top];
    }

    bool isEmpty() const {
        return top == 0;
    }
};