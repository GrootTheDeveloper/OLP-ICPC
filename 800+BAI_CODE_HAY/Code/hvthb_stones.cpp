#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int dp[111][111], a[111], pre[111];

int calc(int l, int r)
{
    if (l == r) return dp[l][r] = a[l];
    if (dp[l][r]) return dp[l][r];
    int ans = inf, sum = pre[r] - pre[l - 1];
    for (int i = l; i < r; i++)
        ans = min(ans , calc(l,i) + calc(i + 1, r) + sum);
    return dp[l][r] = ans;
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("STONES.INP","r",stdin);
    freopen("STONES.OUT","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    cout << calc(1, n) - pre[n];
}
