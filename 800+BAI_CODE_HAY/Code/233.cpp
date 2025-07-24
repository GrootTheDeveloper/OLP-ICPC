#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[555][555], s[555], a[555][555], l, n;
vector <int> g[555];

void dfs(int u)
{
    for (int i = 0; i <= s[u]; i++) dp[i][u] = a[u][i];
    vector <int> d(s[u] + 1, 0);
    for (int v : g[u])
    {
        dfs(v);
        for (int i = 0; i <= s[v]; i++)
            for (int j = s[u]; j >= i; j--)
                d[j] = max(d[j], dp[j - i][u] + dp[i][v]);
        for (int i = 0; i <= s[u]; i++) dp[i][u] = max(dp[i][u], d[i]);
    }
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= l; j++) cin >> a[i][j];
    dfs(1);
    int res = 0;
    for (int i = 0; i <= s[1]; i++) res = max(res, dp[i][1]);
    cout << res;
}
