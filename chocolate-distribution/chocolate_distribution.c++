#include <iostream>
#include <algorithm>
using namespace std;

/* Problem: Given an array of n integers where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. 
There are m students, the task is to distribute chocolate packets such that:
Each student gets one packet.
The difference between the number of chocolates in packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
*/

int min_difference(int choco[], int n, int m) {
	// if no of students = 0 or no of chocolate packets = 0 return 0
	if (n == 0 || m == 0) {
		return 0;
	}

	// no of students can't be greater than no of chocolate packets
	if (n < m) {
		return -1;
	}

	sort(choco, choco + n);

	int min_so_far = INT_MAX;

	for (int i = 0; i + m - 1 < n; i++) {
		int diff = choco[i + m - 1] - choco[i];
		if (min_so_far > diff) {
			min_so_far = diff;
		}
	}

	return min_so_far;
} 

int main() {
	// int n;
	// cin >> n;
	// int choco[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> choco[i];
	// }
	int choco[] = {12, 4, 7, 9, 2, 23, 25, 41,
					30, 40, 28, 42, 30, 44, 48,
					43, 50};
    int n = sizeof(choco)/sizeof(choco[0]); 
    int m = 7;
    cout << min_difference(choco, n, m) << endl;

	return 0;
}