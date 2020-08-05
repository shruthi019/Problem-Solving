#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int x, int y) {
    return x > y;
}

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int a[n];
        int i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, compare);
        long long int diffmax = 0, diffmin = 0;
        for (i = 0; i < n/2; i++) {
            diffmax += abs(a[i] - a[n-i-1]);
        }
        for (i = 0; i < n; i += 2) {
            diffmin += abs(a[i] - a[i+1]);
        }
        cout << diffmin << " " << diffmax << endl;
    }
    return 0;
}
