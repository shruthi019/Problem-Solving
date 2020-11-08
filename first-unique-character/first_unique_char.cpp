#include <iostream>
#include <unordered_map>
using namespace std;

// Problem: https://leetcode.com/problems/first-unique-character-in-a-string/

int first_unique_char(string s) {
    unordered_map<char, int> m;

    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (m[s[i]] == 1) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    string s = "leetcode";
    cout << first_unique_char(s) << endl;
    return 0;
}
