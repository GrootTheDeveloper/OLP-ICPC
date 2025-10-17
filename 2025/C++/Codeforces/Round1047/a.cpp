#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int k, x; cin >> k >> x;
        while (k--) {
            x *= 2;
        }
        cout << x << endl;
    }
}