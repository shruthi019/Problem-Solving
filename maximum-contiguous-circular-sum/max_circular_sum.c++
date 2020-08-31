#include <iostream>
#include <climits>
using namespace std;

#define ll long long 

// Problem: Given n numbers (both +ve and -ve), arranged in a circle, find the maximum sum of consecutive number. 

ll max_sum_subarray(ll a[], ll n) {
    // kadane's algo
    ll max_so_far = INT_MIN;
    ll max_ending_here = 0;
    for (ll i = 0; i < n; i++) {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

ll max_circular_sum(ll a[], ll n) {
    ll max_subarray_sum = max_sum_subarray(a, n);
  
    // if max sum includes wrapping
    // sum of all elements - (- max subarray sum of inverted array)
    // Example 1:
    // 2 -1 3 kadane => 3
    // -2 1 -3 kadane => 1
    // max wrap sum = (2 + (-1) + 3 + 1) = 5
    // max subarray sum = max(3, 5) = 5
    
    // Example 2:
    // 1 2 3 kadane => 6
    // -1 -2 -3 kadane => -1
    // max wrap sum = (1 + 2 + 3 - 1) = 5
    // max subarray sum = max(6, 5) = 6
   
    ll arr_sum = 0;
    for (ll i = 0; i < n; i++) {
        arr_sum += a[i];
        a[i] *= (-1);
    }
    ll max_wrap_sum = arr_sum + max_sum_subarray(a, n);
    return max(max_subarray_sum, max_wrap_sum);
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << max_circular_sum(a, n);
    return 0;
}
