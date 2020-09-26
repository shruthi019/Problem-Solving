#include <iostream>
#include <vector>
using namespace std;

/*
Problem: https://leetcode.com/problems/container-with-most-water/
*/

int maxArea(vector<int>& height) {
        
    int i = 0; 
    int j = height.size() - 1;
    
    int max_area = -1;
    
    while (i < j) {
        max_area = max(max_area, min(height[i], height[j]) * (j - i));
        
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max_area;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}