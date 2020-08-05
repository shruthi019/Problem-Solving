#include <iostream>
using namespace std;

class node{
public:
    node* left;
    node* right;
};

class trie{
    node* root;
    public:
        trie() {
            root = new node();
        }
       
        void insert(int n) {
            node* temp = root;
            for (int i = 31; i >= 0 ; i--){
                int bit = (n >> i) & 1;
                if (bit == 0) {
                    if (temp->left == NULL) {
                        temp->left = new node();
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = new node();
                    }
                    temp = temp->right;
                }
            }
        } 

        int max_xor_helper(int val) {
            node* temp = root;
            int curr_ans = 0;
            for (int j = 31; j >= 0; j--) {
                int bit = (val >> j) & 1;
                if (bit == 0) {
                    if (temp->right != NULL) {
                        temp = temp->right;
                        curr_ans += (1 << j);
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->left != NULL) {
                        temp = temp->left;
                        curr_ans += (1 << j);
                    } else {
                        temp = temp->right;
                    }
                }
            }
            return curr_ans;
        }

        int max_xor(int *input, int n) {
            int max_xor = 0;

            for (int i = 0; i < n; i++) {
                int val = input[i];
                insert(val);
                int curr_max_xor = max_xor_helper(val);
                cout << curr_max_xor << endl;
                max_xor = max(max_xor, curr_max_xor);
            }
            return max_xor;
        }
};

int main() {
    int a[] = {25, 10, 2, 8, 5, 3};
    trie t;
    cout << t.max_xor(a, 6);
    return 0;
}
