#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int x,y,w;
}g[5000005];
bool cmp(node a, node b) { return a.w > b.w;}
int par[2002], sz[2002], n, m;
int a[2002];

void inp()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			++m;
			g[m].x = i;
			g[m].y = j;
			g[m].w = a[i]^a[j];
		}
}
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
	//cout << a << ' ' << b << '\n';
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
	int res = 0;
	for (int i = 1; i <= m; i++)
		if (Union(g[i].x, g[i].y)) res += g[i].w;
			
	

	cout << res;
}

signed main()
{


	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	inp();
	kruskal();
}