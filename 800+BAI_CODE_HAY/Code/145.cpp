#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n, k, a[1001];

void solve()
{
    vector<int> dp(k + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= k; j++)
            if (dp[j - a[i]] != inf) dp[j] = min(dp[j], dp[j - a[i]] + 1);
    if (dp[k] == inf) dp[k] = -1;
    cout << dp[k];

}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
}
