#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/climbing-stairs/ (EASY level)

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    
    int* dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i < n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main() {
    int n = 4;
    cout << climbStairs(n) << endl;
    return 0;
}

/*
 Example n = 4
    1+1+1+1
    1+2+1
    2+1+1
    2+2
    1+1+2
*/
