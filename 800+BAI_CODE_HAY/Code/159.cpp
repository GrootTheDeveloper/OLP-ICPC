#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[1001][1001];
int a[1001];

int mul(int a, int b)
{
    int res = 0;
    while (b)
    {
        if (b&1) res = (res + a) % mode;
        a = (a + a) % mode;
        b /= 2;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][1] = dp[i-1][1] + a[i];

    for (int x = 2; x <= k; x++)
        for (int i = x; i <= n; i++)
            dp[i][x] = (dp[i - 1][x] + mul(dp[i - 1][x - 1], a[i])) % mode;

    cout << dp[n][k];
}
