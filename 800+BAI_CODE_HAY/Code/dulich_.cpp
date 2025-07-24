#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define u first
#define v second
ii eg[300005];
vector <int> g[300005];
int a[300005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int mx = 0, ver = 0;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (a[i] > mx) mx = a[i], ver = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		eg[i].u = u;
		eg[i].v = v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		g[i].push_back(0);
		sort(g[i].begin(), g[i].end(), [](int x, int y)
		{
			return a[x] > a[y];
		});
	}
	vector <int> ans;
	int res = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = eg[i].u, v = eg[i].v;
		int t1 = 0, t2 = 0;
		for (int x1 = 0; x1 < min((int)g[u].size(), 5); x1++)
			for (int x2 = 0; x2 < min((int)g[v].size(), 5); x2++)
			{
				if (g[u][x1] != v && g[u][x1] != g[v][x2] && g[v][x2] != u)
				{
					if (a[g[u][x1]] + a[g[v][x2]] > a[t1] + a[t2])
						t1 = g[u][x1], t2 = g[v][x2];
				}
			}
		int bio = a[u] + a[v] + a[t1] + a[t2];
		if (bio > res)
		{
			res = bio;
			ans.resize(0);
			if (t1) ans.push_back(t1);
			ans.push_back(u);
			ans.push_back(v);
			if (t2) ans.push_back(t2);
		}
	}
	if (res < mx)
	{
		cout << 1 << '\n' << ver << '\n';
		return 0;
	}
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
}



