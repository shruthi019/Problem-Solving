#include <iostream>
#include <queue>
using namespace std;

// Problem: https://www.geeksforgeeks.org/implement-stack-using-queue/

class myStack{
	queue<int> q1;
	queue<int> q2;
public:
	void push(int x) {
		// O(n) - making push costly
		q2.push(x);

		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}

	int pop() {
		// O(1) - making pop efficient
		if (q1.empty()) {
			return -1;
		}
		int f = q1.front();
		q1.pop();
		return f;
	}

	int top() {
		if (q1.empty()) {
			return -1;
		}

		return q1.front();
	}

	bool empty() {
		return q1.empty();
	}
};

class newStack{
	queue<int> q1;
	queue<int> q2;
public:
	void push(int x) {
		// O(1) - making push efficient
		q1.push(x);
	}

	int pop() {
		// O(n) - making pop costly
		if (q1.empty()) {
			return -1;
		}

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		int t = q1.front();
		q1.pop();

		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;

		return t;
	}

	int top() {
		if (q1.empty()) {
			return -1;
		}

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		int t = q1.front();
		q2.push(q1.front());
		q1.pop();

		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;

		return t;
	}

	bool empty() {
		return q1.empty();
	}
};

int main() {
	newStack s;
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	while (!s.empty()) {
		cout << s.pop() << " ";
	}

	cout << endl << endl;

	myStack s1;
	for (int i = 0; i < 10; i++) {
		s1.push(i);
	}

	while (!s1.empty()) {
		cout << s1.pop() << " ";
	}
	return 0;
}