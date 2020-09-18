#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Problem: Given two integer arrays arr1[] and arr2[] sorted in ascending order and an integer k. 
Find k pairs with smallest sums such that one element of a pair belongs to arr1[] and other element belongs to arr2[].
*/

vector<pair<int, int> > find_k_pairs(int arr1[], int arr2[], int n1, int n2, int k) {
	// Naive solution - O(n1 * n2 * log(n1 * n2))

    if (k > n1 * n2) {
		cout << "Not Possible to find " << k << " pairs" << endl;
		exit(0); 
	}

	vector<pair<int, int> > pairs;
	vector<vector<int> > sums;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			sums.push_back({arr1[i] + arr2[j], arr1[i], arr2[j]});
		}
	}

	sort(sums.begin(), sums.end());

	for (int i = 0; i < k; i++) {
		pairs.push_back(make_pair(sums[i][1], sums[i][2]));
	}

	return pairs;
}

vector<pair<int, int> > find_k_pairs_eff(int arr1[], int arr2[], int n1, int n2, int k) {
    // TC: O(k * n1)

    if (k > n1 * n2) {
		cout << "Not Possible to find " << k << " pairs" << endl;
		exit(0);
	}

	vector<pair<int, int> > pairs;

	int visited_index_arr2[n1];
	for (int i = 0; i < n1; i++) {
		visited_index_arr2[i] = 0;
	}
	while (k--) {
		int min_sum = INT_MAX;
		int min_index = 0;

		for (int i = 0; i < n1; i++) {
			if (visited_index_arr2[i] < n2 && arr1[i] + arr2[visited_index_arr2[i]] < min_sum) {
				min_sum = arr1[i] + arr2[visited_index_arr2[i]];
				min_index = i;
			}
		}

		pairs.push_back(make_pair(arr1[min_index], arr2[visited_index_arr2[min_index]]));
		visited_index_arr2[min_index]++;
	}
	return pairs;
}

int main() {
	int arr1[] = {1, 3, 11};
	int arr2[] = {2, 4, 8};

	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int k = 4;

	vector<pair<int, int> > k_pairs = find_k_pairs(arr1, arr2, n1, n2, k);
	for (auto p: k_pairs) {
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
