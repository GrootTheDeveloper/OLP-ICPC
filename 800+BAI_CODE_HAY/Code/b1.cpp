#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int seg[N * 4], top[N], nex[N], chain[N], pos[N], sz[N], face[N], a[N];
int cur_pos, cur_chain;
long long dp[N];
vector<int> g[N];
int n;

void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p)
	{
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void hld(int s, int p = 0)
{
	if (!face[cur_chain])
	{
		face[cur_chain] = s;
		nex[s] = p;
		top[s] = cur_pos + 1;
	}
	chain[s] = cur_chain;
	pos[s] = ++cur_pos;
	update(1, 1, n, cur_pos, a[s]);
	nex[s] = nex[face[cur_chain]];
	top[s] = top[face[cur_chain]];
	
	int nxt = 0;
	for (int v : g[s])
	if (v != p && sz[v] > sz[nxt]) nxt = v;
	if (nxt) hld(nxt, s);
	
	for (int v : g[s])
	if (v != nxt && v != p)
		cur_chain++, hld(v, s);
}

int query(int u, int v)
{
	int ans = 0;
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v])
			swap(u, v);
		ans = max(ans, get(1, 1, n, top[v], pos[v]));
		v = nex[v];
	}
	if (pos[u] > pos[v]) swap(u, v);
	return max(ans, get(1, 1, n, pos[u], pos[v]));
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("SHIP.INP","r",stdin);
	freopen("SHIP.OUT","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	hld(1);
	int k; cin >> k;
	memset(dp, -1, sizeof(dp));
	while (k--)
	{
		int u, v; cin >> u >> v;
		int cur = query(u, v);
		if (u == 1)
			dp[v] = max(dp[v], 1ll * cur);
		if (dp[u] != -1)
			dp[v] = max(dp[v], dp[u] + cur);
	}
	cout << *max_element(dp + 1, dp + n + 1);
}