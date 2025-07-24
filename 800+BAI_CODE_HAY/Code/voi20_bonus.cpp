#include <bits/stdc++.h>
using namespace std;
//#define int long long
//const int oo = -1e15;
long long dp[303][303][155];
int a[303];
long long calc(int l, int r, int k)
{
    if ((r - l + 1) / 2 < k || k == 0) return 0;
    if (r - l == 1 && k == 1) return dp[l][r][k] = abs(a[l] - a[r]);
    if (dp[l][r][k] != -1) return dp[l][r][k];
    long long ans = -1;
    ans = max(ans, abs(a[r] - a[l]) + calc(l + 1, r - 1, k -1));
    ans = max(ans, abs(a[l] - a[l + 1]) + calc(l + 2, r, k -1));
    ans = max(ans, abs(a[r] - a[r - 1]) + calc(l, r - 2, k -1));
    ans = max({ans, calc(l + 1, r, k), calc(l, r - 1, k)});
    return dp[l][r][k] = ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << calc(1, n, k);
}
