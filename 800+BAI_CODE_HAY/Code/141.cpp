#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = -1e9;
int n,s;
int w[101], v[101];
void solve()
{
    vector <int> dp(s + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= w[i]; j--)
            if (dp[j - w[i]] != inf) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    for (int i = 1; i <= s; i++) dp[i] = max(dp[i], dp[i - 1]);
    cout << dp[s];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    solve();
}
