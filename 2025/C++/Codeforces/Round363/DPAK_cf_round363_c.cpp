#include <bits/stdc++.h>
#define STAC static
#define int long long
using namespace std;

const int oo = 1e9;

signed main() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i][0]=rest, [1]=contest, [2]=gym
    STAC int dp[105][3];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = oo;

    dp[1][0] = 1;
    if (a[1] == 1 || a[1] == 3) dp[1][1] = 0;
    if (a[1] == 2 || a[1] == 3) dp[1][2] = 0;

    for (int i = 2; i <= n; i++) {

        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;

        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }

        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }

    int ans = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans;
    return 0;
}
