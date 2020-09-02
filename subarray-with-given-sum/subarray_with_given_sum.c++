#include <iostream>
using namespace std;

// Problem: To find subarray with given sum k in an array consisting of only positive integers

pair<int, int> subarray_simple(int a[], int n, int k) {
	// Time Complexity: O(n^2) worst case
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			sum += a[j-1];
			if (sum == k) {
				return make_pair(i, j-1);
			}
		}
		sum = 0;
	}
	return make_pair(-1, -1);
}

pair<int, int> subarray_efficient(int a[], int n, int k) {
	// Time Complexity: O(n)
	int start = 0, sum = a[0];
	for (int i = 1; i <= n; i++) {
		while (k < sum && start < i - 1) {
			sum = sum - a[start];
			start++;
		}

		if (sum == k) {
			return make_pair(start, i - 1);
		}

		if (i < n) {
			sum += a[i];
		}
	}
	return make_pair(-1, -1);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	pair<int, int> indices = subarray_efficient(a, n, k);
	if (indices == make_pair(-1, -1)) {
		cout << "No subarray exists with given sum" << endl;
	} else {
		cout << "Subarray exists between indices " << indices.first << " and " << indices.second << endl;
	}
	return 0;
}
