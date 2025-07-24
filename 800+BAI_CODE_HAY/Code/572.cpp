#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005], a[100005], r[100005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) cin >> r[i];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 2] + r[i], dp[i - 1] + a[i]);
    cout << dp[n];
}
