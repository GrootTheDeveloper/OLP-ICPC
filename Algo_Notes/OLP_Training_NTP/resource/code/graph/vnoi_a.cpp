#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18;

signed main() {
    int n, x; cin >> n >> x;
    vector<int>a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(3, -oo));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = -oo;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);

        dp[i][1] = max(dp[i - 1][0] + a[i] * x, dp[i - 1][1] + a[i] * x);
        dp[i][1] = max(dp[i][1], a[i] * x);

        dp[i][2] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);

        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << ans;
}