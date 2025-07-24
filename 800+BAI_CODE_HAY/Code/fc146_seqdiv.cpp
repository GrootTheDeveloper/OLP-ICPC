#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int mode = 1e9 + 7;
int f[3003][3003];
int dp[3003][3003];
long long a[3004];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0] = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        for (int key = 1; key <= i; key++)
        {
            dp[key][i] += f[key - 1][sum % key];
            dp[key][i] %= mode;
        }
        for (int key = 1; key <= i; key++)
        {
            f[key][sum % (key + 1)] += dp[key][i];
            f[key][sum % (key + 1)] %= mode;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[i][n], ans %= mode;
    cout << ans;
}
