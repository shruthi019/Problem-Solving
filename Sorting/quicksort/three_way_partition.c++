#include<iostream>
using namespace std;

/*
Problem:
Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts.
1) All elements smaller than lowVal come first.
2) All elements in range lowVal to highVVal come next.
3) All elements greater than highVVal appear in the end.
The individual elements of three sets can appear in any order.
*/

// Dutch National Flag based QuickSort

void three_way_partition(int arr[], int n, int lo, int hi) {
	// lo and hi denote range of values

	int start = 0, end = n - 1;

	for (int i = 0; i <= end;) {
		if (arr[i] < lo) {
			swap(arr[i++], arr[start++]);
		} else if (arr[i] > hi) {
			swap(arr[i], arr[end--]);
		} else {
			i++;
		}
	}
	return;
}

int main() {
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    //int arr[] = {0, 1, 2, 2, 2, 2, 0, 0, 0, 2 , 1, 1};
	//int arr[] = {11, 32, 22, 42, 15, 16, 13, 11, 1, 50, 60, 40, 31, 21, 505, 62};
	
	int n = sizeof(arr) / sizeof(arr[0]);

	three_way_partition(arr, n, 10, 20);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
