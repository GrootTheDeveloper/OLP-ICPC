#include <bits/stdc++.h>
using namespace std;
#define int long long 
int par[1005], siz[1005];
int n;
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

void Union(int a, int b)
{
	a = find(a); b = find(b);
	if (a != b)
	{
		if (siz[a] < siz[b]) swap(a,b);
		par[b] = a;
		siz[a] += siz[b];
	}
}



signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	make_set();
	Union(1,5);
	cout << find(1) << ' ' << find(5) << '\n';
	Union(1,4);
	cout << find(4) << ' ';

}