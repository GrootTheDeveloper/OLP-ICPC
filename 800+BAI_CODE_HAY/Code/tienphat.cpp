#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii a[3003];
int dp[3003], pre[3003];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].fi;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + a[i].se;
        for (int j = i - 1; j >= 1; j--)
            dp[i] = min(dp[i], dp[j - 1] + a[j].se + (pre[i] - pre[j]) - a[j].fi * (i - j));
    }
    cout << dp[n];
}
