#include <bits/stdc++.h>
using namespace std;
#define int long long 

int par[100005], sz[100005], n, m, COUNT, SIZE = 1;

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
	COUNT--;
	par[b] = a;
	sz[a] += sz[b];
	SIZE = max(SIZE, sz[a]);
}

void process()
{	
	cin >> n >> m;
	COUNT = n;
	make_set();
	while (m--)
	{
		int a,b; cin >> a >> b;
		Union(a,b);
		cout << COUNT << ' ' << SIZE << '\n';
	}
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	process();
}