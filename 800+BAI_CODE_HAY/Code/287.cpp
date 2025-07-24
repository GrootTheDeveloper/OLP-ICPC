#include <bits/stdc++.h>
using namespace std;
#define int long long 
int tin[100005];
vector <int> g[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
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
	for (int c : vec) cout << c << ' ';
}