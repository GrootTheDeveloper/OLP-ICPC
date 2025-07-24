#include <bits/stdc++.h>
using namespace std;
#define int long long 
int par[100005], sz[100005], n, m;

struct node
{
	int x,y,t;
}g[100005];
bool cmp(node a, node b) { return a.t < b.t;}

void make_set()
{
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i]  = 1;
	}
}
int find(int v)
{
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}
bool Union(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a,b);
	par[b] = a;
	sz[a] += sz[b];
	return find(1) == find(n);
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> g[i].x >> g[i].y >> g[i].t;
	sort(g + 1, g + m + 1, cmp);
	make_set();
	for (int i = 1; i <= m; i++)
		if (Union(g[i].x, g[i].y)) return cout << g[i].t, void();

}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();
}