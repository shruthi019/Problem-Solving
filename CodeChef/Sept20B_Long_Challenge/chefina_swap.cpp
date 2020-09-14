#include <iostream>
#include <cmath>
using namespace std;

// Problem: https://www.codechef.com/SEPT20B/problems/CHFNSWAP

long long partition(long long n) {
    // 2x(x+1) = n(n+1)
    // 2x^2 + 2x - n(n+1) = 0
    return (long long)((-2.0 + sqrt(4.0 + 8.0 * (n * n + n))) / 4.0);
}

long long nc2(long long x) {
    return (x * (x - 1)) / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (((n * (n + 1)) / 2) & 1) {
            cout << 0 << endl;
            continue;
        }
        
        long long ans = 0;
        long long x = partition(n); // x is the point upto which we consider first part, next part is x + 1 ... n
        
        ans += n - x;
        
        // if sum of 2 parts is already equal then internal swapping within the 2 parts is possible too
        // example - case n = 20 (sum of 1...14 = sum of 15...20)
        if (2 * x * (x + 1) == n * (n + 1)) {
            ans += nc2(x) + nc2(n - x);
        }
        
        cout << ans << endl;
    }
    return 0;
}