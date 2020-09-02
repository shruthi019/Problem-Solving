#include <iostream>
using namespace std;

// Problem: Write a function int equilibrium_index(int[] a, int n); that given a sequence arr[] of size n, returns an equilibrium index (if any) or -1 if no equilibrium indexes exist.

int equilibrium_index(int a[], int n) {
	int array_sum = 0;
	for (int i = 0; i < n; i++) {
		array_sum += a[i];
	}
	int left_sum = 0;
	for (int i = 0; i < n; i++) {
		array_sum -= a[i];
		if (left_sum == array_sum) {
			return i;
		}
		left_sum += a[i];
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int eqm_idx = equilibrium_index(a, n);
	if (eqm_idx == -1) {
		cout << "No equilibrium index" << endl;
	} else {
		cout << "Equilibrium index is " << eqm_idx << endl;
	}
	return 0;
}