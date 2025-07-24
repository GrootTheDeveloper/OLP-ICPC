#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int n,k, a[1004];

void solve()
{
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= k; j++)
        {
            dp[j] += dp[j - a[i]];
            dp[j] %= mode;
        }
    cout << dp[k];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
}
