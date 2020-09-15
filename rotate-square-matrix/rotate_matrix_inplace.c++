#include <iostream>
using namespace std;

// Problem: Given a square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.

void rotate(int mat[10][10], int n) {
	// Time Complexity: O(n^2)
	// Space Complexity: O(1)

	for (int x = 0; x < n / 2; x++) {
		for (int y = x; y < n - x - 1; y++) {
			// store current cell in temp
			int temp = mat[x][y];

			// move value from right to left
			mat[x][y] = mat[y][n - 1 - x];

			// move value from bottom to right
			mat[y][n - 1 - x] = mat[n - 1 - x][n - 1 -y];

			// move value from left to bottom
			mat[n - 1 - x][n - 1 - y] = mat[n - 1 - y][x];

			// store temp in left
			mat[n - 1 - y][x] = temp;
		}
	}
	return;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n; 

	int mat[10][10];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	rotate(mat, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}