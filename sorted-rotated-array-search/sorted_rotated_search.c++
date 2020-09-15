#include <iostream>
using namespace std;

/*
Problem: An element in a sorted array can be found in O(log n) time via binary search. 
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.
*/

int binary_search(int a[], int s, int e, int key) {
	if (s > e) {
		return -1;
	}

	int mid = (s + e) / 2;

	if (a[mid] == key) {
		return mid;
	}

	if (a[mid] < key) {
		return binary_search(a, mid + 1, e, key);
	}

	return binary_search(a, s, mid - 1, key);
}

int find_pivot(int a[], int s, int e) {
	if (s > e) {
		return -1;
	}
	if (s == e) {
		return s;
	}

	int mid = (s + e) / 2;

	// example: 5 6 7 0 1 2 3 
	if (mid < e && a[mid] > a[mid + 1]) {
		return mid;
	}

	if (mid > s && a[mid] < a[mid - 1]) {
		return mid - 1;
	}

	if (a[s] >= a[mid]) {
		return find_pivot(a, s, mid - 1);
	}

	return find_pivot(a, mid + 1, e);
}

int pivoted_binary_search(int a[], int s, int e, int key, int pivot) {
	if (pivot == -1) {
		return binary_search(a, s, e, key);
	}

	if (a[pivot] == key) {
		return pivot;
	}

	if (a[0] <= key) {
		return binary_search(a, 0, pivot - 1, key);
	}

	return binary_search(a, pivot + 1, e, key);
}

int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	int key;
	cin >> key;

	int pivot = find_pivot(a, 0, n - 1);
	cout << pivoted_binary_search(a, 0, n - 1, key, pivot) << endl;

	return 0;
}
