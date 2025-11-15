#include <bits/stdc++.h>
#define int long long
using namespace std;

void balance(multiset<int> &left, multiset<int> &right) {
    if (left.size() > right.size() + 1) {
        right.insert(*left.rbegin());
        left.erase(*left.rbegin());
    }
    else if (right.size() > left.size() + 1) {
        left.insert(*right.begin());
        right.erase(*right.begin());
    }
}

signed main() {
    multiset<int> left, right;
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            if (left.find(x) == left.end() && right.find(x) == right.end()) {
                if (left.empty()) {
                    if (right.empty()) {
                        left.insert(x);
                    }
                    else if (x >= *right.begin()) {
                        left.insert(*right.begin());
                        right.erase(*right.begin());
                        right.insert(x);
                    }
                    else {
                        left.insert(x);
                    }
                }
                else if (x <= *left.rbegin()) left.insert(x);
                else right.insert(x);
            }
            else {
                if (left.find(x) != left.end()) {
                    left.erase(x);
                }
                else right.erase(x);
            }

            balance(left, right);
        }
        else {
            int n = left.size() + right.size();
            int ans = 0;
            bool check = false;
            if (n % 2 == 1) {
                if (left.size() > right.size()) {
                    ans = *left.rbegin();
                }
                else {
                    ans = *right.begin();
                }
            }
            else {
                int l = *left.rbegin();
                int r = *right.begin();
                ans = l + r;
                if (ans % 2 == 1) check = true;
                ans /= 2;
            }
            cout << ans ;
            if (check) cout << ".5";
            cout << endl;
        }

    }
    return 0;
}