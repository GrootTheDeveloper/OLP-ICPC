#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1001][1001];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
    int x = m, y = n;
    vector <int> vec;
    while (true)
    {
        vec.push_back(a[x][y]);
        if (dp[x-1][y] + a[x][y] == dp[x][y]) x -= 1;
        else y -= 1;
        if (x ==0) break;
    }
    cout << dp[m][n] << '\n';
    reverse(vec.begin(),end(vec));
    for (int x : vec) cout << x << ' ';
}
