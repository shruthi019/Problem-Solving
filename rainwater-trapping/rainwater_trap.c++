#include <iostream>
using namespace std;

// Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

int rain_water_trapped(int heights[], int n) {
	int left_max[n];
	int right_max[n];
	int i;
	left_max[0] = heights[0];
	right_max[n-1] = heights[n-1];

	for (i = 1; i < n; i++) {
		left_max[i] = max(heights[i], left_max[i-1]);
	}
	for (i = n-2; i >= 0; i--) {
		right_max[i] = max(heights[i], right_max[i+1]);
	}

	int total_rain_trapped = 0;

	for (i = 0; i < n; i++) {
		total_rain_trapped += min(left_max[i], right_max[i]) - heights[i];
	}
	return total_rain_trapped;
}

int rainwater_space_optimized(int heights[], int n) {
    int lo = 0, hi = n - 1;
    int left_max = 0, right_max = 0;
    int total_rain_trapped = 0;
    while (lo <= hi) {
        if (heights[lo] < heights[hi]) {
            if (heights[lo] > left_max) {
                left_max = heights[lo];
            } else {
                total_rain_trapped += left_max - heights[lo];
            }
            lo += 1;
        } else {
            if (heights[hi] > right_max) {
                right_max = heights[hi];
            } else {
                total_rain_trapped += right_max - heights[hi];
            }
            hi -= 1;
        }
    }
    return total_rain_trapped;
}

int main() {
	/*
	Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
	left_max:		0  1  1  2  2  2  2  3  3  3  3  3
	right_max:		3  3  3	 3	3  3  3	 3	2  2  2	 1
	water:			0  0  1  0  1  2  1  0  0  1  0  0
	Output: 6
	*/
	int n;
	cin >> n;
	int heights[n];
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	cout << rainwater_space_optimized(heights, n) << endl;
	return 0;
}
