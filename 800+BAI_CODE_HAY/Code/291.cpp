#include <bits/stdc++.h>
using namespace std;
#define int long long 
int tin[100005];
vector <int> g[100005];
int d[100005][30];
bool us[100005];
char a[100005];
void dfs(int u)
{
	us[u] = true;
	d[u][a[u] - 'a'] = 1;
	for (int v : g[u])
	{
		if (!us[v]) dfs(v);
		for (char c = 'a'; c <= 'z'; c++)
		{
			int x = c - 'a';
			d[u][x] = max(d[u][x], d[v][x] + (a[u] == c));
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		tin[v]++;
	}
	queue <int> q;
	for (int i = 1; i <= n; i++) if (tin[i] == 0) q.push(i);
	vector <int> vec;
	while (q.size())
	{
		int u = q.front(); q.pop();
		vec.push_back(u);
		for (int v : g[u])
			if (--tin[v] == 0) q.push(v); 
	}
	reverse(begin(vec), end(vec));
	for (int c : vec) if (!us[c]) dfs(c);
	int res = 0;
	for (int i = 1; i <= n; i++) 
		for (int c = 'a'; c <= 'z'; c++)
			res = max(res, d[i][c - 'a']);
	cout << res;
}