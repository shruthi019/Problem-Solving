#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarraySumZero(int *a, int n) {
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (a[i] == 0 and len == 0) len = 1;
        if (pre == 0) len = max(len, i+1);
        if (m.find(pre) != m.end()) {
            len = max(len, i - m[pre]);
        }
        else {
            m[pre] = i;
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << longestSubarraySumZero(a, n);
    return 0;
}
