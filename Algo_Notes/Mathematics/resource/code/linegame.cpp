#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18 + 7;

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(n + 1, vector<int>(2, -oo));
    f[1][0] = a[1];
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i][0], a[i]);
        f[i][0] = max(f[i][0], f[i - 1][0]);
        f[i][0] = max(f[i][0], f[i - 1][1] + a[i]);
        
        f[i][1] = max(f[i][1], f[i - 1][1]);
        f[i][1] = max(f[i][1], f[i - 1][0] - a[i]);
    }

    int ans = -oo;

    for (int i = 1; i <= n; i++) {
        ans = max({ans,f[i][0], f[i][1]});
    }
    cout << ans;
}