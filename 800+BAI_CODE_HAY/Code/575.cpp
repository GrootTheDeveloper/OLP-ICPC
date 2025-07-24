#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii a[100005];
int dp[100005], last[100005];
bool cmp(ii a, ii b)
{
    return a.se < b.se;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) last[i] = a[i].se;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(last + 1, last + n + 1, a[i].fi) - last - 1;
        dp[i] = max(dp[i - 1], dp[pos] + a[i].se - a[i].fi + 1);
    }
    cout << dp[n];
}
