#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int chain[N], face[N], pos[N], top[N], nex[N], sz[N], a[N];
int cur_chain, cur_pos;
vector<int> g[N];
long long bit[N];
int n, q;

void update(int idx, int val)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

long long get(int l, int r)
{
	long long ans = 0;
	--l;
	for (; r; r -= r & -r) ans += bit[r];
	for (; l; l -= l & -l) ans -= bit[l];
	return ans;
}

void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p)
		dfs(v, u), sz[u] += sz[v];
}
void hld(int s, int p = 0)
{
	if (!face[cur_chain])
	{
		face[cur_chain] = s;
		top[s] = cur_pos + 1;
		nex[s] = p;
	}	
	pos[s] = ++cur_pos;
	chain[s] = cur_chain;
	update(cur_pos, a[s]);
	nex[s] = nex[face[cur_chain]];
	top[s] = top[face[cur_chain]];
	int nxt = 0;
	for (int v : g[s])
		if (sz[v] > sz[nxt] && v != p) nxt = v;
	if (nxt) hld(nxt, s);
	for (int v : g[s])
	if (v != nxt && v != p)
		cur_chain++, hld(v, s);
}

void Query(int u, int v)
{
	long long  ans = 0;
	int tmp = a[u] + a[v];
	while (chain[u] != chain[v])
	{
		if (chain[u] > chain[v])
			swap(u, v);
		ans += get(top[v], pos[v]);
		v = nex[v];
	}
	ans += get(min(pos[u], pos[v]), max(pos[u], pos[v]));
	cout << ans * 2 - tmp << '\n';
}

void solve()
{
	while (q--)
	{
		int kind, u, v; cin >> kind >> u >> v;
		if (kind == 1) update(pos[u], abs(v) - a[u]), a[u] = abs(v);
		else Query(u, v);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] = abs(a[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	hld(1);
	solve();
}