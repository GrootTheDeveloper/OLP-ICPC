#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
vector<ii> g[1005];
int par[10005];
int n,m,s,k;

void inp()
{
	cin >> n >> m;
	for (int i = 1, x, y, w; i <= m; i++)
	{
		cin >> x >> y >> w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	cin >> s;
}

void solve()
{
	vector <int> d(n + 1, inf);
	d[s] = 0;
	priority_queue <ii, vector <ii>, greater<ii>> q;
	q.push({0,s});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se;
		int dic = top.fi;
		if (dic > d[u]) continue;
		for (ii c : g[u])
		{
			int w = c.se;
			int v = c.fi;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push({d[v],v});
				par[v] = u;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i] << ' '; cout << '\n';
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x; cin >> x;
		vector <int> path;
		while (x != 0)
		{
			path.push_back(x);
			x = par[x];
		}
		reverse(begin(path), end(path));
		for (int c : path) cout << c << ' ';
		cout << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inp();
	solve();
	cout << "Time : " << clock()/(double)1000 << " sec";
}