#include <iostream>
#include <stack>
using namespace std;

// Problem: https://leetcode.com/problems/min-stack/

class min_stack{
    stack<int> s;
    int min_ele;
public:
    void push(int x) {
        if (s.empty()) {
            min_ele = x;
            s.push(x);
            return;
        }

        if (x < min_ele) {
            s.push(2 * x - min_ele);
            min_ele = x;
        } else {
            s.push(x);
        }

        return;
    }

    void pop() {
        if (s.empty()) {
            return;
        }

        if (s.top() < min_ele) {
            min_ele = 2 * min_ele - s.top();
        } 

        s.pop();

        return;
    }

    int top() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int t = s.top();

        if (t < min_ele) {
            return min_ele;
        }

        return t; 
    }

    int min() {
        return min_ele;
    }
};


int main() {
    min_stack ms;

    // Pushing elements
    ms.push(10);
    ms.push(-3);
    ms.push(2);
    ms.push(-9);

    cout << ms.min() << endl;

    ms.pop();
    
    cout << ms.min() << endl;

    ms.pop();
    ms.pop();

    cout << ms.min() << endl;

    return 0;
}
