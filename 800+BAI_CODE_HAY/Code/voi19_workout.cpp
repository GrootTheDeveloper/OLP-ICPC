#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
struct node 
{
	int u, v, w;
}eg[100005];
struct DATA
{
	int kind, a, b;
}op[11];
vector <int> g[100005];
int d[11][100005], par[11][100005];
int n, m, k;
void dijkstra(int s, int pos)
{
	vector <bool> mark(n + 5, false);
	queue <ii> q;
	q.push({s, 0});
	mark[s] = true;
	while (q.size())
	{
		ii top = q.front(); q.pop();
		int u = top.fi, p = top.se;
		for (int id : g[u])
		{
			int v = eg[id].u + eg[id].v - u, w = eg[id].w;
			if (v == p) continue;
			if (!mark[v])
			{
				d[pos][v] = d[pos][u] + w;
				par[pos][v] = u;
				mark[v] = true;
				q.push({v, u});
			} else
			{
				if (d[pos][v] > d[pos][u] + w)
				{
					d[pos][v] = d[pos][u] + w;
					par[pos][v] = u;
					q.push({v, u});
				}
			}
		}
	}
}


void sub1()
{
	vector <int> v1, v2;
	for (int u = op[1].b; u != 0; u = par[1][u]) v1.push_back(u);
	for (int u = op[2].b; u != 0; u = par[2][u]) v2.push_back(u);
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	int x = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == v2[i]) x = v1[i];
		else break;
	}
	cout << d[1][x];
}
void sub2()
{
	vector <int> v1, v2;
	for (int u = op[1].b; u != 0; u = par[1][u]) v1.push_back(u);
	for (int u = op[2].b; u != 0; u = par[2][u]) v2.push_back(u);
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	// for (int x : v1) cout << x << ' ';
	// cout << '\n';
	// for (int x : v2) cout << x << ' ';
	// cout << '\n';
	map <ii, bool> f;
	unordered_map <int, int> val;
	int ans1 = 0, ans2 = 0;
	
	for (int i = 0; i < v1.size() - 1; i++)
		f[{v1[i], v1[i + 1]}] = true;
	
	for (int i = 0; i < v2.size() - 1; i++)
		if (f.find({v2[i], v2[i + 1]}) != f.end())
		{
			int dic = d[1][v2[i]] - d[2][v2[i]];
			if (dic == 0) ans1 += d[1][v2[i + 1]] - d[1][v2[i]];
			else
			{
				val[dic] += d[1][v2[i + 1]] - d[1][v2[i]];
				ans2 = max(ans2, val[dic]);
			}
		}
	if (op[2].kind == 0) cout << ans1;
	else cout << max(ans1, ans2);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg[i].u = u;
		eg[i].v = v;
		eg[i].w = w;
		g[u].push_back(i);
		g[v].push_back(i);	
	}
	for (int i = 1; i <= k; i++)
	{
		if (i == 1)
			cin >> op[i].a >> op[i].b;
		else
			cin >> op[i].kind >> op[i].a >> op[i].b;
	}
	for (int i = 1; i <= k; i++) dijkstra(op[i].a, i);
	if (k == 2)
	{
		sub2();
	}
}