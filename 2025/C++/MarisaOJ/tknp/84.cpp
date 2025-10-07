#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

int f(int x) { // dem so luong so dep <= x
    return x / 3 + x/5 + x/7-x/15-x/21-x/35+x/105;
}

signed main() {
    int k; cin >> k;
    int l = 3, r = 1e18;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        int SUM = f(mid);
        if (SUM >= k) {
            ans = mid; 
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
}