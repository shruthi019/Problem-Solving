#include <iostream>
#include <stack>
using namespace std;

// Problem: https://www.geeksforgeeks.org/queue-using-stacks/

class myQueue{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x) {
		// O(n) - making push costly
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int pop() {
		// O(1) - making pop efficient
		if (s1.empty()) {
			return -1;
		}

		int t = s1.top();
		s1.pop();
		return t;
	}

	int top() {
		if (s1.empty()) {
			return -1;
		}
		return s1.top();
	}

	bool empty() {
		return s1.empty();
	}
};

class newQueue{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x) {
		// O(1) - making push efficient
		s1.push(x);
	}
	
	int pop() {
		// O(n) - making pop costly
		if (s1.empty()) {
			return -1;
		}

		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		int t = s2.top();
		s2.pop();

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		return t;
	}

	int top() {
		if (s1.empty()) {
			return -1;
		}

		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		int t = s2.top();

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		return t;
	}

	bool empty() {
		return s1.empty();
	}
};

int main() {
	myQueue q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.pop() << " ";
	}

	cout << endl << endl;

	newQueue q2;
	for (int i = 0; i < 10; i++) {
		q2.push(i);
	}

	while (!q2.empty()) {
		cout << q2.pop() << " ";
	}

	return 0;
}