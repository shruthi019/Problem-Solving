#include <bits/stdc++.h>
using namespace std;

// ques: given array of n students who have to do a[i] work, redistribute the work such that all students do equal work
// if you take m units away from one, i.e. a[i] - m units, then another student gets k times that work i.e. a[j] + k * m units
// 1.00 <= k <= 10.00
// output the min work that each student has to do correct to 2 decimal places

double minwork(int n, double k, vector<int>& a) {
    double lo = 0;
    double hi = DBL_MAX;
    double mid;
    double extra;
    double borrow;
    double ans = -1;

    while (hi - lo > 0.0001) {
        mid = lo + (hi - lo) / 2;
        borrow = 0;
        extra = 0;

        for (int& x : a) {
            if (x < mid) {
                borrow += mid - x;
            } else {
                extra += x - mid;
            }
        }
        
        if (extra * k >= borrow) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return ans;
}

int main() {
    int n = 2;
    double k = 1.45;
    vector<int> a = {5, 20};
    cout << setprecision(2) << fixed << minwork(n, k, a);
}