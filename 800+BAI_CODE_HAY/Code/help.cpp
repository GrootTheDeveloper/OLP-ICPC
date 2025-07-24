#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 5e3 + 5;
struct dta{
	int x,y,w;
}g[100003];
struct node
{
	int k,s,id;
} Case[500005];
bool cmp(dta a, dta b) {return a.w < b.w;}
bool omp(node a, node b) {return a.s < b.s;}
int ans[500005], par[maxn], sz[maxn], n, m, q;

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
	if (par[v] == v) return v;
	return par[v] = find(par[v]);
}
void Union(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	par[b] = a;
}
int calc(int v)
{
	v = find(v);
	return sz[v];
}
void solve()
{
	cin >> n >> m >> q;
	make_set();
	for (int i = 1; i <= m; i++) cin >> g[i].x >> g[i].y >> g[i].w;
	sort(g + 1, g + m + 1, cmp);
	for (int i = 1; i <= q; i++)
	{
		cin >> Case[i].k >> Case[i].s;
		Case[i].id = i;
	}
	sort(Case + 1, Case + q + 1, omp);
	int l = 1;
	for (int i = 1; i <= q; i++)
	{
		while (l <= m && g[l].w <= Case[i].s)
		{
			Union(g[l].x, g[l].y);
			l++;
		}
		ans[Case[i].id] = calc(Case[i].k);
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("help.inp","r",stdin);
	freopen("help.out","w",stdout);
	int t; cin >> t;
	while (t--)
		solve();	
}