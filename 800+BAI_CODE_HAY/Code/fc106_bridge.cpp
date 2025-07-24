#include <bits/stdc++.h>
using namespace std;

long long Ans[200005], ans;
int par[200005], sz[200005], x[200005], y[200005];
int n, m;

void make_set()
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}
void Union(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	ans = ans - 1ll * sz[a] * (n - sz[a]) + 1ll * sz[a] * (n - sz[a] - sz[b]);
	sz[a] += sz[b];
	par[b] = a;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> x[i] >> y[i];

	ans = n * (n - 1) / 2;
	make_set();
	for (int i = m; i >= 1; i--)
	{
		Ans[i] = ans;
		Union(x[i], y[i]);
	}
	for (int i = 1; i <= m; i++) cout << Ans[i] << '\n';
}