#include <iostream>
#include <chrono>
#include <ratio>
#include <cassert>
using namespace std;

struct Stack {
    int * stack;
    int top;
    int size;
};

const int START = 10;
const int INC = 1;

void grow(Stack &s)
{
    auto new_size = s.size + INC; //3
    auto new_stack = new int[new_size]; //3
    for (int i=0; i<s.size; i++) //4N
        new_stack[i] = s.stack[i];
    delete [] s.stack; //1
    s.stack = new_stack; //2
    s.size = new_size; //2
}

void push(Stack &s,int x)
{
    if (s.top == s.size) 
        grow(s);
    s.stack[s.top++] = x;
}

int pop(Stack &s)
{
    return s.stack[--s.top];
}

void test(int N)
{
    Stack s{new int[START],0,START};

    for (int i=0; i<N; i++) {
        push(s,i);
        push(s,i);
        pop(s);
    }
    for (int i=0; i<N; i++) {
        push(s,i);
        pop(s);
        pop(s);
    }

    assert(s.top == 0);
    delete s.stack;
}

int main()
{
    for (auto N : {100,1000,10000,100000,1000000,10000000,100000000}) {
        auto t1 = chrono::high_resolution_clock::now();
        test(N);
        auto t2 = chrono::high_resolution_clock::now();
        auto d = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
        cout << d << "ns total, " << d/N << "ns/iteration, when N=" << N << "\n";
    }
}
