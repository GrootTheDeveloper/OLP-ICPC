#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k) dp[i] = i + 1;
        else dp[i] = (dp[i - 1] + dp[i - k]) % mode;
    }
    cout << dp[n];
}
