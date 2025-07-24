#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5;
const int inf  = 1e15;
int n,m,k;
vector<ii> g[maxn];
int t[maxn], p[maxn], dp[maxn], par[maxn];
int d[maxn];
void inp()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i = 1; i <= k; i++) cin >> p[i] >> t[i], par[p[i]] = p[i];
}

void sub3()
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= k; i++) q.push({0,p[i]}), d[p[i]] = 0, dp[p[i]] = inf;
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, kc = top.fi;
		if (kc > d[u]) continue;
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				par[v] = par[u];
				q.push({d[v],v});
			}
			if (par[v] && par[u] && par[u] != par[v])
				{	dp[par[u]] = min(dp[par[u]], d[u] + d[v] + w);
					dp[par[v]] = min(dp[par[v]], d[u] + d[v] + w);
				}
		}
	}
	for (int i = 1; i <= k; i++) if(t[i] == 1) d[p[i]] = dp[p[i]]; 
	for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}

void solve()
{
	for (int i = 1; i <= n; i++) d[i] = inf;
	sub3();
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	freopen("milktea.inp","r",stdin);
	freopen("milktea.out","w",stdout);
	inp();
	solve();
}