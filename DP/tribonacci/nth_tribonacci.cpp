#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/n-th-tribonacci-number/ (EASY level)

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n <= 2) {
        return 1;
    }
    
    int one = 0;
    int two = 1;
    int three = 1;
    int ans;
    
    for (int i = 3; i < n + 1; i++) {
        ans = one + two + three;
        one = two;
        two = three;
        three = ans;
    }
    
    return ans;
}

int main() {
	int n = 4;
	cout << tribonacci(n) << endl;
	return 0;
}