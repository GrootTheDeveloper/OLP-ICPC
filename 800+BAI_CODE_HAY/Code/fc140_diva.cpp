#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
vector<int> d[2222];
void init()
{
    for (int i = 1; i <= 2e3; i++)
        for (int j = i; j <= 2e3; j+=i) d[j].push_back(i);
}
int dp[1003][2003], a[1003];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    for (int i = 1; i <= n; i++)
        fill(dp[i], dp[i] + 2000 + 1, inf);
    for (int i = 1; i <= 2e3; i++)
        dp[1][i] = abs(a[1] - i);
    for (int i = 2; i <= n; i++)
    {
        for (int x = 1; x <= 2e3; x++)
            for (int y : d[x])
                dp[i][x] = min(dp[i][x], dp[i - 1][y] + abs(x - a[i]));
    }
    int ans = inf;
    for (int i = 1; i <= 2e3; i++)
        ans = min(ans, dp[n][i]);
    cout << ans;
}
