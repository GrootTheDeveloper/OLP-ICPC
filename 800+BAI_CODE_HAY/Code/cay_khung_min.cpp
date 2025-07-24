#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int siz[1005],par[1005];
struct node{
	int x,y,w;
}g[1005];

bool cmp(node a, node b)
{
	return ((a.w == b.w)? a.x < b.x : a.w < b.w);
}

void make_set()
{
	for (int i = 1; i <= n; i++) 
	{
		par[i] = i;
		siz[i] = 1;
	}
}

int find(int v)
{
	if (par[v] == v) return v;
	return par[v] = find(par[v]);
}

bool Union(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a,b);
	par[b] = a;
	siz[a] += siz[b];
	return true;
}

void kruskal()
{
	make_set();
	sort(g + 1, g + m + 1, cmp);
	vector <node> vec;
	int d = 0;
	for (int i = 1; i <= m && vec.size() < n - 1; i++)
		if (Union(g[i].x, g[i].y)) vec.push_back(g[i]), d += g[i].w;
	cout << d << '\n';
	for (node i : vec)
		cout << i.x << ' ' << i.y << ' ' << i.w << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> g[i].x >> g[i].y >> g[i].w;
	kruskal();
}