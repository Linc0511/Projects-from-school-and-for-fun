template <typename T> 
class Stack
{
    T * data;
    int top;

public:
    Stack(int maxsize) {
        data = new T[maxsize];
        top = 0;
    }
    
    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        data[top] = value;
        top++;
    }

    T pop() {
        top--;
        T value = data[top];
        return value;
    }
    
    int get_size() {
        return top;
    }

    bool isEmpty() {
        return top == 0;
    }

    int get_top() {
        return top;
    }
};
