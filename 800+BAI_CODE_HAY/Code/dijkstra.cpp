#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
const int inf = 1e9;
int n, m, s;
vector <ii> g[1005];

void dijkstra(int s);

void inp()
{
	cin >> n >> m >> s;
	for (int i = 1, x, y, w; i <= m; i++)
	{
		cin >> x >> y >> w;
		g[x].push_back({y,w});
	}
	dijkstra(s);
}
int par[1005];
void dijkstra(int s)
{
	vector <int> d(n + 1, inf);
	d[s] = 0;
	priority_queue <ii, vector<ii>, greater<ii>> q;
	q.push({0,s});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.second;
		int kc = top.first;
		if (kc > d[u]) continue;
		for (ii c : g[u])
		{
			int v = c.first;
			int w = c.second;
			if (d[u] + w < d[v])
			{
				d[v] = d[u] + w;
				par[v] = u;
				q.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << d[i] <<  ' ';
	int k; cin >> k;
	vector <int> vec = {k};
	while (par[k] != 0)
	{
		k = par[k];
		vec.push_back(k);
	}
	reverse(vec.begin(), vec.end());
	cout << '\n';
	for (int c : vec) cout << c << ' ';
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inp();	
}