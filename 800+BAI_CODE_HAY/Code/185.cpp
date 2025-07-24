#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e9;
int x[100005], d[100005];
int s[100005];
vector <int> g[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k, p; cin >> n >> m >> k >> p;
	queue <int> q1,q2;
	for (int i = 1; i <= n; i++) x[i] = d[i] = inf;
	for (int i = 1; i <= k; i++)
	{
		int ai; cin >> ai;
		q1.push(ai);
		x[ai] = 0;
	}
	for (int i = 1; i <= p; i++) 
		cin >> s[i];

	for (int i = 1; i <= m; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (q1.size())
	{
		int u = q1.front(); q1.pop();
		for (int v : g[u])
		{
			if (x[v] > x[u] + 1)
			{
				x[v] = x[u] + 1;
				q1.push(v);
			}
		}
	}
	q2.push(1);
	d[1] = 0;
	while (q2.size())
	{
		int u = q2.front(); q2.pop();
		for (int v : g[u])
		if (d[u] + 1 < x[v] && d[v] > d[u] + 1)
		{
			d[v] = d[u] + 1;
			q2.push(v);
		}
	}
	string res = "NO";
	for (int i = 1; i <= p; i++)
		if (d[s[i]] < x[s[i]]) res = "YES";
	cout << res;

}