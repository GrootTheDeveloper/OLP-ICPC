#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	int x,y,w;
} g[1005];
int n,m;
int par[1005], siz[1005];

bool cmp(node a, node b) { return a.w < b.w;} 	
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
	sort(g + 1, g + m + 1, cmp);
	int d = 0;
	vector <node> vec;
	make_set();
	
	for (int i = 1; i <= m && vec.size() < n -1 ; i++)
		if (Union(g[i].x , g[i].y)) vec.push_back(g[i]), d += g[i].w;
	
	if (vec.size() != n-1) return cout << "Khong ton tai",void();
	cout << d << '\n';
	for (node x : vec)
		cout << x.x << ' ' << x.y << ' ' << x.w << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> g[i].x >> g[i].y >> g[i].w;
	kruskal();
}