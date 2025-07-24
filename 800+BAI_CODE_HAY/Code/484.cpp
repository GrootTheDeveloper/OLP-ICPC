#include <bits/stdc++.h>
using namespace std;


set<int>::iterator it, lef, rig; 
set<int> Set;
bool mark[100005];
int d[100005], face[100005], tin[100005], up[100005][18], timer;
vector<int> g[100005];
int ans = 0;
void dfs(int u, int p = 0)
{
	tin[u] = ++timer;
	face[timer] = u;
	up[u][0] = p;
	for (int i = 1; i <= 17; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];

	for (int v : g[u])
	if (v != p)
	{
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int lift(int v, int k)
{
	for (int i = 17; i >= 0; i--)
		if (k >> i & 1) v = up[v][i];
	return v;
}
int lca(int u, int v)
{
	if (d[u] > d[v]) swap(u, v);
	v = lift(v, d[v] - d[u]);
	if (v == u ) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) 
			u = up[u][i], v = up[v][i];
	return up[u][0];
}
int dis(int u, int v)
{
	int x = lca(u, v);
	return d[u] + d[v] - 2 * d[x];
}
void solve1(int x)
{
	if (Set.empty())
	{
		Set.insert(tin[x]);
		return cout << 0 << '\n', void();
	}
	if (*Set.begin() > tin[x] || tin[x] > *Set.rbegin())
	{
		int A = *Set.begin(), B = *Set.rbegin();
		ans -= dis(face[A], face[B]);
		ans += dis(x, face[A]);
		ans += dis(x, face[B]);
		Set.insert(tin[x]);
	}
	else
	{
		Set.insert(tin[x]);
		it = lef = rig = Set.lower_bound(tin[x]);
		lef--, rig++;
		int A = *lef, B = *rig;
		ans -= dis(face[A], face[B]);
		ans += dis(face[A], x);
		ans += dis(face[B], x);
	}
	cout << ans / 2 << '\n';
}
void solve2(int x)
{
	Set.erase(tin[x]);
	if (Set.empty())
		return cout << 0 << '\n', void();
	
	if (*Set.begin() > tin[x] || tin[x] > *Set.rbegin())
	{
		int A = *Set.begin(), B = *Set.rbegin();
		ans += dis(face[A], face[B]);
		ans -= dis(x, face[A]);
		ans -= dis(x, face[B]);
	}
	else
	{
		lef = rig = Set.upper_bound(tin[x]);
		lef--;
		int A = *lef, B = *rig;
		ans += dis(face[A], face[B]);
		ans -= dis(face[A], x);
		ans -= dis(face[B], x);
	}
	cout << ans / 2 << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	while (q--)
	{
		int x; cin >> x;
		if (!mark[x]) solve1(x);
		else solve2(x);
		mark[x] = !mark[x];
	}
}