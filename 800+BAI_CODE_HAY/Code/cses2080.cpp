#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 5;
int d[N], sz[N];
vector <int> g[N];
bool del[N];
int n, k, root;

void calc_size(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p && !del[v])
	{
		calc_size(v, u);
		sz[u] += sz[v];
	}
}
int get(int u, int p, int n)
{
	for (int v : g[u])
		if (v != p && !del[v] && sz[v] > n / 2) 
			return get(v, u, n);
	return u;
}
void update(int u, int p, unordered_map<int,int> &dp)
{
	if (d[u] > k) return;
	dp[d[u]]++;
	for (int v : g[u])
		if (v != p && !del[v]) update(v, u, dp);
}
void dfs(int u, int p, int &ans, unordered_map<int,int> &dp)
{
	for (int v : g[u])
	{
		if (v == p || del[v]) continue;
		d[v] = d[u] + 1;
		if (d[v] <= k)
		{
			if (dp.find(k - d[v]) != dp.end()) ans += dp[k - d[v]];
			dfs(v, u, ans, dp);
		}
		if (u == root)
			update(v, u, dp);
	}
}


int solve(int u)
{
	int ans = 0;
	calc_size(u);
	root = get(u, 0, sz[u]);
	d[root] = 0;
	unordered_map <int,int> dp;
	dp[0] = 1;
	dfs(root, 0, ans, dp);
	del[root] = true;
	for (int v : g[root])
		if (!del[v]) ans += solve(v);
	return ans;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << solve(1);
}