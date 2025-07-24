#include <bits/stdc++.h>
using namespace std;
#define int long long 

int D;
vector<int> g[100005];
int dp[100005];
int w[100005];
int ans;
int n;
void dfs(int u, int p = 0)
{
	dp[u] = 1;
	for (int v : g[u]) if (v != p)
	{
		dfs(v, u);
		D = max(D, dp[u] + dp[v]);
		dp[u] = max(dp[u], dp[v] + 1);
	}
}

int d[100005];
int Ans[100005];
void bfs(int s)
{
	vector<bool> us;
	us.resize(n + 1, false);
	queue<int> q;
	q.push(s);
	d[s] = 1;
	Ans[s] = w[s];
	us[s] = true;

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : g[u])
		if (!us[v])
		{
			us[v] = true;
			d[v] = d[u] + 1;
			Ans[v] = Ans[u] + d[v] * w[v];
			q.push(v);
		}
	}

	for (int i = 1; i <= n; i++)
	if (d[i] == D) ans = max(ans, Ans[i]);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	
	for (int i = 1; i <= n; i++)
	if (g[i].size() == 1) bfs(i);

	cout << ans;
}