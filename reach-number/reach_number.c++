#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/reach-a-number/

int get_sum(int n) {
    return (n * (n + 1)) / 2;
}
    
int reach_number(int target) {
    target = abs(target);
    
    int ans = 0;
    
    while (get_sum(ans) < target || (get_sum(ans) - target) & 1) {
        ans++;
    }
    
    return ans;
}

int main() {
	int target = 9;
	cout << "Steps required: " << reach_number(target) << endl;
	return 0;
}