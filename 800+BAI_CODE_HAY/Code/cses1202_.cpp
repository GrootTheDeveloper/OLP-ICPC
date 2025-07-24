#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define fi first
#define se second
const int mode = 1e9 + 7;
const int inf = 1e15;

vector <ii> g[100005];
int d[100005], cnt[100005], fl[100005], fh[100005];


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
	//	g[v].emplace_back(u, w);
	}
	priority_queue <ii, vector<ii>, greater<ii>> q;
	fill(d, d + n + 1, inf);
	q.push({0, 1});
	d[1] = 0;
	cnt[1] = 1;
	while (q.size())
	{
		auto x = q.top(); q.pop();
		int u = x.se, kc = x.fi;
		if (kc > d[u]) continue;
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				cnt[v] = cnt[u];
				fl[v] = fl[u] + 1;
				fh[v] = fh[u] + 1;
				q.push({d[v], v});
			} else if (d[v] == d[u] + w)
			{
				cnt[v] = (cnt[v] + cnt[u]) % mode;
				fh[v] = max(fh[v], fh[u] + 1);
				fl[v] = min(fl[v], fl[u] + 1);	
			}
		}
	}
	cout << d[n] << ' ' << cnt[n] << ' ' << fl[n] << ' ' << fh[n];	

}