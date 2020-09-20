#include <iostream>
using namespace std;

/*
Problem: Given an array that is sorted and then rotated around an unknown point. 
Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.
*/

int find_pivot(int arr[], int l, int r, int n) {
	// TC = O(logn)

	if (r < l) {
		return n - 1;
	}

	if (l == r) {
		return l;
	}

	int mid = (l + r) / 2;

	if (mid < r && arr[mid] > arr[mid + 1]) {
		return mid;
	}

	if (mid > l && arr[mid - 1] > arr[mid]) {
		return mid - 1;
	}

	if (arr[mid] < arr[r]) {
		return find_pivot(arr, l, mid - 1, n);
	}

	return find_pivot(arr, mid + 1, r, n);
}

bool pair_present(int arr[], int n, int target_sum) {
	// TC = O(n), SC = O(1)

	int pivot = find_pivot(arr, 0, n - 1, n);

	int l = (pivot + 1) % n;
	int r = pivot;

	while (l != r) {
		if (arr[l] + arr[r] == target_sum) {
			return true;
		} else if (arr[l] + arr[r] < target_sum) {
			l = (l + 1) % n;
		} else {
			r = (n + r - 1) % n;
		}
	}

	return false;
}

int no_of_pairs(int arr[], int n, int target_sum) {
	// TC = O(n), SC = O(1)

	int pivot = find_pivot(arr, 0, n - 1, n);

	int l = (pivot + 1) % n;
	int r = pivot;

	int count = 0;

	while (l != r) {
		if (arr[l] + arr[r] == target_sum) {
			count++;

            if (l == (n + r - 1) % n) {
				return count;
			}

            l = (l + 1) % n;
			r = (n + r - 1) % n;
		} else if (arr[l] + arr[r] < target_sum) {
			l = (l + 1) % n;
		} else {
			r = (n + r - 1) % n;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	int arr[] = {11, 15, 6, 7, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target_sum = 16;

	if (pair_present(arr, n, target_sum)) {
		cout << "Pair present" << endl;
	} else {
		cout << "No Pair present" << endl;
	}
	cout << "Number of Pairs = " << no_of_pairs(arr, n, target_sum) << endl;

	return 0;
}
