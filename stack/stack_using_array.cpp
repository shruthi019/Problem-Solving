#include <iostream>
using namespace std;
#define size 10

// Implementing stack using array

class stack{
    int arr[size];
    int max_idx = size - 1;
    int top = -1;
public:
    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == max_idx;
    }

    void push(int x) {
        if (is_full()) {
            cout << "Stack is full, cannot insert " << x << endl;
            return;
        }
        top += 1;
        arr[top] = x;
        return;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack is empty, cannot pop element" << endl;
            return -1;
        }
        top -= 1;
        return arr[top + 1];
    }

    int peak() {
        if (is_empty()) {
            cout << "Stack is empty, cannot return peak element" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    stack s;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }
    s.push(11);
    cout << s.pop() << endl;
    cout << s.peak() << endl;
    while (!s.is_empty()) {
        s.pop();
    }
    s.pop();
    cout << s.peak() << endl;
    return 0;
}