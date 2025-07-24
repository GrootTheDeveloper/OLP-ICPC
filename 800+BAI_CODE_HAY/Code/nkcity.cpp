#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int x,y,w;
}g[200005];
bool cmp(node a, node b) { return a.w < b.w;}
int par[100005], sz[100005], n, m;
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
	return true;
}

void kruskal()
{
	sort(g + 1, g + m + 1, cmp);
	make_set();
	vector <node> vec;
	int res = 0;
	for (int i = 1; i <= m && vec.size() < n - 1; i++)
		if (Union(g[i].x, g[i].y)) vec.push_back(g[i]), res += g[i].w;
	if (vec.size() == n-1) cout << res;
	else cout << "IMPOSSIBLE";
}

void inp()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> g[i].x >> g[i].y >> g[i].w;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	kruskal();	
}