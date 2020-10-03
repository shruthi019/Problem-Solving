#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/squares-of-a-sorted-array

vector<int> sorted_squares_eff(vector<int> v) {
	// 2 pointer method
	// TC: O(n) 
	// SC: O(n)

	vector<int> squares;
	int n = v.size();
	int j = 0;
	while (j < n && v[j] < 0) {
		j++;
	}

	int i = j - 1;

	while (i >= 0 && j < n) {
		if (v[i] * v[i] < v[j] * v[j]) {
			squares.push_back(v[i] * v[i]);
			i--;
		} else {
			squares.push_back(v[j] * v[j]);
			j++;
		}
	}

	while (i >= 0) {
		squares.push_back(v[i] * v[i]);
		i--;
	}

	while (j < n) {
		squares.push_back(v[j] * v[j]);
		j++;
	}

	return squares;
}

vector<int> sorted_squares(vector<int> A) {
	// TC: O(nlogn)
	// SC: O(n)

	vector<int> squares;
    for (int i = 0; i < A.size(); i++) {
        squares.push_back(A[i]*A[i]);
    }
    sort(squares.begin(), squares.end());

    return squares;
}

int main() {
	vector<int> v = {-4, -3, 1, 3, 4, 8};
	vector<int> squares = sorted_squares_eff(v);

	for (int x: squares) {
		cout << x << ", ";
	}
	cout << endl;
	
	return 0;
}
