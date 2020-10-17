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

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '/' || op == '*') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return -1;
}

bool is_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}


int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infix << endl;

    string postfix = "";

    // operand stack 
    stack s;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        } else {
            if (infix[i] == '(') {
                s.push(infix[i]);
            } else if (infix[i] == ')') {
                while (s.peak() != '(') {
                    postfix += s.pop();
                }
                s.pop();
            } else {
                while (!s.is_empty() && s.peak() != '(' && precedence(s.peak()) >= precedence(infix[i])) {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    while (!s.is_empty()) {
        postfix += s.pop();
    }
    
    cout << postfix << endl;
    return 0;
}