#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end(), greater<int>());
        int COST = 0;
        for (int i = 1; i <= k; i++) {
            COST += a[i];
        }
        
    }
}