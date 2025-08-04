#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
    }
    int ans = 0;
    for (int len = 1; len <= n; len++) {
        for (int r = len; r <= n; r++) {
            int l = r - len + 1;
            ans = max(ans, f[r] ^ f[l - 1]);
        }
    }
    cout << ans;
}