#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/sort-array-by-parity/

vector<int> sort_parity_twoptr(vector<int>& A) {
	// sort in place using 2 pointers
	// TC: O(n)
	// SC: O(1)

	int i = 0, j = A.size() - 1;

	while (i < j) {
		if (A[i] % 2 > A[j] % 2) {
			swap(A[i], A[j]);
		}

		if (A[i] % 2 == 0) {
			i++;
		} 

		if (A[j] % 2 == 1) {
			j--;
		}
	}

	return A;
}

vector<int> sort_parity(vector<int>& A) {
	// TC: O(n)
	// SC: O(n)
	
	vector<int> ans;
    vector<int> odd;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            ans.push_back(A[i]);
        } else {
            odd.push_back(A[i]);
        }
    }
    for (int x: odd) {
        ans.push_back(x);
    }
    return ans;
}

int main() {
	vector<int> v = {4, 3, 1, 3, 48, 80};
	vector<int> ans = sort_parity(v);
	vector<int> ans2 = sort_parity_twoptr(v);

	for (int x: ans) {
		cout << x << ", ";
	}
	cout << endl;
	for (int x: ans2) {
		cout << x << ", ";
	}
	cout << endl;

	return 0;
}
