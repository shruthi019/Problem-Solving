#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/min-cost-climbing-stairs/

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int* dp = new int[n];
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    }
    
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
