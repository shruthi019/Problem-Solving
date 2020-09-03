#include <iostream>
#include <algorithm>
using namespace std;

// Problem: Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f. 

int* zigzag_array(int a[], int n) {
	// first sort the array and then swap elements starting from index 1
	// naive solution
	// Time Complexity: O(nlogn)
	sort(a, a+n);
	for (int i = 1; i < n - 1; i += 2) {
		swap(a[i], a[i + 1]);
	} 
	return a;
}

int* zigzag_array_optimized(int a[], int n) {
	// Time Complexity: O(n)
	bool lesser_than = true;
	for (int i = 0; i < n - 1; i++) {
		if (lesser_than) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		} else {
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		}
		lesser_than = !lesser_than;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int* zig_zag_array = zigzag_array_optimized(a, n);
	for (int i = 0; i < n; i++) {
		cout << zig_zag_array[i] << " ";
	}
	return 0;
}