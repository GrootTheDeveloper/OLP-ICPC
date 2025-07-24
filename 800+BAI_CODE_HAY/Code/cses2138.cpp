#include <bits/stdc++.h>
using namespace std;

bitset <50004> d[50004];
int in[50004];
vector <int> g[50004];
bool vs[50004];

void dfs(int u)
{
	vs[u] = true;
	d[u].set(u);
	for (int v : g[u])
	{
		if (!vs[v]) dfs(v);
		d[u] |= d[v];
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		in[v]++;
	}
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);
	vector <int> vec;
	while (q.size())
	{
		int u = q.front(); q.pop();
		vec.push_back(u);
		for (int v : g[u])
			if (--in[v] == 0) q.push(v);
	}
	reverse(begin(vec), end(vec));
	for (int x : vec)
		if (!vs[x]) dfs(x);
	
	for (int i = 1; i <= n; i++)
		cout << d[i].count() << ' ';
}