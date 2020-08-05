#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, e;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        sort(v.begin(), v.end(), compare);
        int activity_count = 1;
        int finish_time = v[0].second;

        for (int i = 1; i < n; i++) {
            if (v[i].first >= finish_time) {
                finish_time = v[i].second;
                activity_count += 1;
            }
        }
        cout << activity_count << endl;
        v.clear();
    }
    return 0;
}
