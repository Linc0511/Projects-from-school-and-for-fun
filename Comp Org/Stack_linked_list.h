template <typename T>
class Stack {
private:
class Node {
public:
    T data;
    Node* next;

    Node(const T& data_, Node* next_ = nullptr)
        : data(data_), next(next_)
    {}
};

    Node* head;

public:
    Stack()
        : head(nullptr)
    {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        head = new Node(item, head);
    }

    T pop() {
        assert(!isEmpty());
        Node* nodeToDelete = head;
        T popped = nodeToDelete->data;
        head = head->next;
        delete nodeToDelete;
        return popped;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
