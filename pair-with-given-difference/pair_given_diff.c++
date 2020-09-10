#include <iostream>
#include <algorithm>
using namespace std;

// Problem: Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.

pair<int, int> find_pair(int a[], int n, int k) {
	// Naive, simplest solution
	// O(n^2)

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(a[i] - a[j]) == k) {
				return make_pair(a[i], a[j]);
			}
		}
	}

	cout << "Not possible" << endl;
	exit(0);
}

pair<int, int> find_pair_efficient(int a[], int n, int k) {
	// O(nlogn) due to sorting 

	sort(a, a + n);
	int i = 0; // index of array
	int j = 1; // index of array

	// O(n)
	// example to understand code -> 1 3 4 10, k = 1
	while (i < n && j < n) {
		if (i != j && a[j] - a[i] == k) {
			return make_pair(a[j], a[i]);
		} else if (a[j] - a[i] < k) {
			j++;
		} else {
			i++;
		}
	}

	cout << "No pair" << endl;
	exit(0);
}


int main() {
	int array[] = {4, 3, 1, 10};
	int n = sizeof(array)/sizeof(array[0]);
	int k;
	cin >> k;

	pair<int, int> p = find_pair_efficient(array, n, k);

	cout << p.first << " " << p.second << endl;
	return 0;
}