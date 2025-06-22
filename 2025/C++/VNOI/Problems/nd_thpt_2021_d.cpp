#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("WORK.INP", "r", stdin);
    freopen("WORK.OUT", "w", stdout);
    
    int n; cin >> n;
    vector<int> t(n + 1), p(n);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> p[i];
    }
    vector<int> dp(n + 1, 0);
    dp[1] = t[1];
    dp[2] = min(dp[1] + t[2], p[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + t[i], p[i - 1] + dp[i - 2]);
    }
    cout << dp[n];
    return 0;
}