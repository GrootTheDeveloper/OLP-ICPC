#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>

vector <int> g[200005];
int dic[200005], d[200005], fh[200005][19], up[200005][19], n, a[200005];

void dfs1(int u, int p = 0)
{
	up[u][0] = p;
	dic[u] = dic[p] + a[u];
	fh[u][0] = a[p];
	for (int i = 1; i <= 18; i++) 
	{
		fh[u][i] = max(fh[u][i - 1], fh[up[u][i - 1]][i - 1]);
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (int v : g[u]) if (v != p)
	{
		d[v] = d[u] + 1;
		dfs1(v, u);
	}
}

ii lca(int u, int v)
{
	if (d[u] > d[v]) swap(u,v);
	int res = 0;
	for (int i = 18; i >= 0; i--)
		if ((d[v] - d[u]) >> i & 1)
		{
			res = max(res, fh[v][i]);
			v = up[v][i];
		}
	if (u == v) return {u, res};
	for (int i = 18; i >= 0; i--)
		if (up[u][i] != up[v][i])
		{
			res = max({res, fh[u][i], fh[v][i]});
			u = up[u][i];
			v = up[v][i];
		}
	return {up[u][0], max({res, fh[u][0], fh[v][0]})};
}
bool sub1()
{
	if (n > 1000) return false;
	dfs1(1);
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			ii x = lca(i,j);
			int mx = max({x.second, a[i], a[j]}), dit = dic[i] + dic[j] - 2 * dic[x.first] + a[x.first];
			res += (2 * mx < dit);	
		}
	cout << res << ' ';
	return true;

}
int ans, dp[200005];
void dfs2(int u, int p = 0)
{
	for (int v : g[u]) if (v != p)
	{
		dfs2(v, u);
		ans += dp[v] - 1;
		ans += dp[v] * dp[u];
		dp[u] += dp[v];
	}
	dp[u] += 1;
}
bool sub2()
{
	int high = 0;
	for (int i = 1; i <= n; i++) high = max(high, a[i]);
	if (high != 1) return false;
	dfs2(1);
	cout << ans;
	return true;

}
vector <int> vec;
void topo(int u, int p = 0)
{
	vec.push_back(u);
	for (int v : g[u]) if (v != p)
		topo(v, u);
}
bool sub3()
{
	int pos = 0;
	for (int i = 1; i <= n; i++) 
	{
		if (g[i].size() > 2) return false;
		if (g[i].size() == 1) pos = i;
	}
	topo(pos);
	for (int c : vec) cout << c << ' ';
		int sum = 0;
	for (int i = 1; i <= 1e18; i++) sum += i;
		cout << sum;
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (sub1()) return 0;
	if (sub2()) return 0;
	if (sub3()) return 0;
	if (n <= 5e4) return sub1();
	//if (sub3()) return 0;

}