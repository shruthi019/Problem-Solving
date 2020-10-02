#include <iostream>
using namespace std;

// Normal Quicksort Implementation

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int partition(int arr[], int lo, int hi) {
	int pivot = arr[hi];

	int j = lo - 1;
	for (int i = lo; i < hi; i++) {
		if (arr[i] < pivot) {
			j++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[j + 1], &arr[hi]);
	return j + 1;
}

void quicksort(int arr[], int lo, int hi) {
	if (lo < hi) {
		int pi = partition(arr, lo, hi);

		quicksort(arr, lo, pi - 1);
		quicksort(arr, pi + 1, hi);
	}
}

int main() {
	int arr[] = {39,-39,28,3,1,-3,-4,9};
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
