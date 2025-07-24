#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;
struct dta
{
	int x,y,w;
}option[303];
vector <ii> g[10005];
vector <ii> rg[10005];
int s,t,n,m,k;


void inp()
{
	cin >> n >> m >> k >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		rg[v].emplace_back(u,w);
		//g[v].emplace_back(u,w);
	}
	for (int i = 1; i <= k; i++)
		cin >> option[i].x >> option[i].y >> option[i].w;
}
void dijkstra(int s, vector <int> &d)
{
	d[s] = 0;
	priority_queue <ii, vector<ii>, greater<ii>> q;
	q.push({d[s],s});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, kc = top.fi;
		if (kc > d[u]) continue;
		for (ii x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push({d[v],v});
			}
		}
	}
}

void solve()
{
	vector <int> d1(n + 1, inf), d2(n + 1, inf);
	dijkstra(s,d1);
	swap(g,rg);
	dijkstra(t,d2);
	int res = d1[t];
	for (int i = 1; i <= k; i++)
	{
		int x = option[i].x, y = option[i].y, w = option[i].w;
		res = min({res, d1[x] + d2[y] + w, d1[y] + d2[x] + w});
	}
	if (res >= inf) cout << -1;
	else cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	inp();
	solve();

}
