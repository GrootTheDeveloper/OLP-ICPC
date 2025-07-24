#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int x,y,w;
}d[100005];
int par[10005], sz[10005], n, p, c[10005], low = INT_MAX;
bool cmp(node a, node b) { return a.w < b.w;}
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
bool Union(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a,b);
	par[b] = a;
	sz[a] += b;
	return true;
}

void inp()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> c[i], low = min(low, c[i]);
	for (int i = 1; i <= p; i++)
		{
			cin >> d[i].x >> d[i].y >> d[i].w;
			d[i].w = d[i].w * 2 + c[d[i].x] + c[d[i].y];
		}
}

void kruskal()
{
	sort(d + 1, d + p + 1, cmp);
	make_set();
	vector <node> vec;
	int res = 0;
	for (int i = 1; i <= p && vec.size() < n-1; i++)
		if (Union(d[i].x, d[i].y)) vec.push_back(d[i]), res += d[i].w;
	cout << res + low;
	
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	kruskal();

}