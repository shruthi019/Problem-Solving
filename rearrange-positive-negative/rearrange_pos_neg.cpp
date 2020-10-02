#include <iostream>
using namespace std;

/*
Problem:
An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]
*/

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void rearrange(int arr[], int n) {
	int j = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			j++;
			swap(&arr[i], &arr[j]);
		}
	}

	int neg_start = 0, pos_start = j + 1;

	while (pos_start < n && neg_start < pos_start && arr[neg_start] < 0) {
		swap(&arr[neg_start], &arr[pos_start]);
		pos_start++;
		neg_start += 2;
	}

	return;
}

int main() {
	int arr[] = {1, -5, -6, -92, 13, -78, -39, -29, -3, -45, 33, -6, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	rearrange(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
