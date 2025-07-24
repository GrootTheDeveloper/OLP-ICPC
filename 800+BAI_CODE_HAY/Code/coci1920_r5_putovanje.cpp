#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int u, v, c, d;
}eg[100005];

int n, cnt[100005], d[100005], par[100005];
vector <int> g[100005];
void dfs(int u, int p = 0)
{
	for (int id : g[u])
	{
		int v = eg[id].u + eg[id].v - u;
		if (v == p) continue;
		d[v] = d[u] + 1;
		par[v] = id;
		dfs(v, u);
	}
}
void path(int u, int v)
{
	while (u != v)
	{
		int dic = d[u] - d[v];
		if (dic > 0)
		{
			int id = par[u];
			cnt[id]++;
			u = eg[id].u + eg[id].v - u;
		}
		if (dic < 0)
		{
			int id = par[v];
			cnt[id]++;
			v = eg[id].u + eg[id].v - v;
		}
		if (dic == 0)
		{
			cnt[par[u]]++;
			cnt[par[v]]++;
			u = eg[par[u]].u + eg[par[u]].v - u;
			v = eg[par[v]].u + eg[par[v]].v - v;
		}
	}
}
void sub1()
{
	dfs(1);
	for (int i = 1; i < n; i++)
		path(i, i + 1);
	int res = 0;
	for (int i = 1; i < n; i++)
		res += min(eg[i].c * cnt[i], eg[i].d);
	cout << res;
}

int a[100005], pos[100005], dif[100005], in[100005], val[100005];
int lim = 0;

void Dfs(int u, int p = 0)
{
	pos[u] = ++lim;
	for (int id : g[u])
	{
		int v = eg[id].u + eg[id].v - u;
		if (v == p) continue;
		a[lim] = id;
		Dfs(v, u);
	}
}
void sub2()
{
	int vertex = 0;
	for (int i = 1; i <= n; i++) 
		if (in[i] == 1) vertex = i;
	Dfs(vertex);
	for (int i = 1; i < n; i++)
	{
		dif[min(pos[i], pos[i + 1])]++;
		dif[max(pos[i], pos[i + 1])]--;
	}

	val[1] = dif[1];
	for (int i = 2; i < n; i++)
		val[i] = val[i - 1] + dif[i];
	for (int i = 1; i < n; i++)
		cnt[a[i]] = val[i];

	int res = 0;
	for (int i = 1; i < n; i++)
		res += min(cnt[i] * eg[i].c, eg[i].d);
	cout << res;

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, c, d; cin >> u >> v >> c >> d;
		eg[i].u = u;
		eg[i].v = v;
		eg[i].c = c;
		eg[i].d = d;
		g[u].push_back(i);
		g[v].push_back(i);
		in[u]++;
		in[v]++;
	}
	if (n <= 2000) sub1();
	else sub2();
}