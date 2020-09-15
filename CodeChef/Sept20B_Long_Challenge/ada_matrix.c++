#include <iostream>
using namespace std;

// Problem: https://www.codechef.com/SEPT20B/problems/ADAMAT

void transpose_matrix(int a[][64], int n, int idx) {
    for (int i = idx; i >= 1; i--) {
        if (a[0][i] == i + 1) {
            a[0][i] = n * i + 1;
        } else {
            a[0][i] = i + 1;
        }
    }
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    int mat[64][64];
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cin >> mat[i][j];
	        }
	    }
	    
	    int count = 0;
	    for (int i = n - 1; i >= 1; i--) {
	        if (mat[0][i] != i + 1) {
	            count += 1;
	            transpose_matrix(mat, n, i);
	        }
	    }
	    
	    cout << count << endl;
	    
	}
	return 0;
}
