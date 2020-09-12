#include <iostream>
#include <algorithm>
using namespace std;

/* 
Problem: Given arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop.
*/

int min_platforms(int arr[], int dep[], int n) {
	// Naive solution
	// O(n^2)
	
	int platforms = 1;
	int minimum_platforms = 1;

	for (int i = 0; i < n; i++) {
		platforms = 1;
		for (int j = i + 1; j < n; j++) {
			if ((arr[j] >= arr[i] && arr[j] <= dep[i]) || (arr[i] >= arr[j] && arr[i] <= dep[j])) {
				platforms += 1;
			}
			minimum_platforms = max(minimum_platforms, platforms);
		}
	}

	return minimum_platforms;
}

int min_platforms_efficient(int arr[], int dep[], int n) {
	// Efficient solution - O(n)
	// Sort the arrays first

	sort(arr, arr + n);
	sort(dep, dep + n);

	int i = 1;
	int j = 0;
	int platforms = 1;
	int minimum_platforms = 1;

	while (i < n && j < n) {
		if (arr[i] <= dep[j]) {
			platforms += 1;
			i += 1;
		} else {
			platforms -= 1;
			j += 1;
		}
		minimum_platforms = max(minimum_platforms, platforms);
	}

	return minimum_platforms;
}

int main() {
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << min_platforms_efficient(arr, dep, n) << endl;

	return 0;
}
