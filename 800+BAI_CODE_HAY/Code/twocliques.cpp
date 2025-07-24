#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int u, vector<vector<int>> &g, vector<bool> &mark)
{
	mark[u] = true;
	for (int v : g[u])
		if (!mark[v]) dfs(v, g, mark);
}
void solve()
{
	vector<vector<int>> g;
	g.resize(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int ai; cin >> ai;
			if (ai)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	int cnt = 0;
	vector<bool> mark(n + 1, false);
	for (int i = 1; i <= n; i++)
		if (!mark[i]) cnt++, dfs(i, g, mark);
	cout << (cnt <= 2? "YES" : "NO") << '\n';
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		solve();
	}
}