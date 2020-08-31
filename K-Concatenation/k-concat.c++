#include <iostream>
#include <climits>
using namespace std;

#define ll long long 

ll max_subarray_sum(ll a[], ll n, ll k) {
    ll max_so_far = INT_MIN;
    ll max_ending_here = 0;
    for (ll i = 0; i < n * k; i++) {
		max_ending_here += a[i % n];
		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
		} 
		if (max_ending_here < 0) {
			max_ending_here = 0;
		}
	}
    return max_so_far;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    ll n, k;
	    cin >> n >> k;
	    ll a[n];
	    ll arr_sum = 0;
	    for (ll i = 0; i < n; i++) {
	        cin >> a[i];
	        arr_sum += a[i];
	    }
	    if (k <= 2) {
	        cout << max_subarray_sum(a, n, k) << endl;
	    } else if (arr_sum < 0) {
	        cout << max_subarray_sum(a, n, 2) << endl;
	    } else {
	        cout << max_subarray_sum(a, n, 2) + arr_sum * (k - 2)  << endl;
	    }
	}
	return 0;
}
