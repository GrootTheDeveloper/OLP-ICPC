#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = -1e12, dp[100005], a[100005];
vector <int> g[100005];

void dfs(int u, int p = 0)
{
    dp[u] = a[u];
    ans = max(ans, a[u]);
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        ans = max(ans, dp[u] + dp[v]);
        dp[u] = max(dp[u], dp[v] + a[u]);
    }
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << ans;
}
