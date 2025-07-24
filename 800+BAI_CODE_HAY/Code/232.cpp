#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

vector <int> g[100005];
int dp[4][100005];


void dfs(int u, int p = 0)
{
	dp[1][u] = dp[2][u] = dp[3][u] = 1;
	for (int v : g[u]) if (v != p)
	{
		dfs(v, u);
		dp[1][u] = (dp[2][v] + dp[3][v]) % mode * dp[1][u] % mode;
		dp[2][u] = (dp[1][v] + dp[3][v]) % mode * dp[2][u] % mode;
		dp[3][u] = (dp[1][v] + dp[2][v]) % mode * dp[3][u] % mode;
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << (dp[1][1] + dp[2][1] + dp[3][1]) % mode;
}