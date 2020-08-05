#include <iostream>
#include <unordered_set>
using namespace std;

bool checkSubarraySumZero(int *a, int n){
    unordered_set<int> s;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (pre == 0 or s.find(pre) != s.end()) { 
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool b = checkSubarraySumZero(a, n);
    if (b) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}
