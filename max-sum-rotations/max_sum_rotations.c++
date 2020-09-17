#include <iostream>
using namespace std;

// Problem: Given an array arr[] of n integers, find the maximum that maximizes the sum of the value of i*arr[i] where i varies from 0 to n-1.

int max_sum(int arr[], int n) {
	// Naive Solution -> TC: O(n^2)

	int msum = INT_MIN;
	int csum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int index = (i + j) % n;
			csum += arr[index] * j;
		}
		msum = max(msum, csum);
		csum = 0;
	}

	return msum;
}

int max_sum_efficient(int arr[], int n) {
	// TC: O(n), SC: O(1)
	// Approach:
	// Using previously calculated sum to calculate next sums
	// Multiplier of arr[i-1] changes from 0 to n-1
	// The multipliers of other elements decreases by 1, so (total_sum - arr[i-1]) is subtracted from csum

	int total_sum = 0;
	for (int i = 0; i < n; i++) {
		total_sum += arr[i];
	}

	int csum = 0;
	for (int i = 0; i < n; i++) {
		csum += i * arr[i];
	}

	int msum = csum;

	for (int i = 1; i < n; i++) {
		int next_csum = csum - (total_sum - arr[i-1]) + arr[i-1] * (n - 1);
		csum = next_csum;
		msum = max(msum, csum);
	}

	return msum;
}

int find_pivot(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[(i + 1) % n]) {
			return i;
		}
	}
}

int max_sum_sorted_array(int arr[], int n) {
	// Works for sorted, rotated array
	// We know max sum when it is in ascending order
	// TC: O(n), SC: O(1)

	int pivot = find_pivot(arr, n);
	int csum = 0;
	int diff = n - 1 - pivot; 

	for (int i = 0; i < n; i++) {
		csum += i * arr[(i + diff - 1) % n];
	}

	return csum;
}

int main() {
	//int arr[] = {8, 3, 1, 2};
	int arr[] = {4, 5, 1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << max_sum(arr, n) << endl;
	cout << max_sum_efficient(arr, n) << endl;
	cout << max_sum_sorted_array(arr, n) << endl;

	return 0;
}

/*
Example:
{8, 3, 1, 2} = 8*0 + 3*1 + 1*2 + 2*3 = 11
{3, 1, 2, 8} = 3*0 + 1*1 + 2*2 + 8*3 = 29 -- max
{1, 2, 8, 3} = 1*0 + 2*1 + 8*2 + 3*3 = 27
{2, 8, 3, 1} = 2*0 + 8*1 + 3*2 + 1*1 = 17
*/
