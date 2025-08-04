#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(2, -oo));

        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1] + (a[i] <= a[i - 1] + 1 ? 0 : 1));
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}
