#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003], a[1003];
int par[100005], sz[100005];

void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) { return (v == par[v]? v : par[v] = Find(par[v]));}
void unite(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);   
	par[b] = a;
	sz[a] += sz[b];
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	make_set(n);
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		unite(u, v);
	}
	for (int i = 1; i <= k; i++)
		cin >> a[i];

	for (int i = 1; i <= k; i++)
	for (int j = k; j >= i; j--)
	{
		dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
		if (Find(a[i]) == Find(a[j]))
			dp[i][j] = max(dp[i - 1][j + 1] + (i != j? 2 : 1), dp[i][j]);
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	for (int j = k; j >= i; j--)
		ans = max(ans, dp[i][j]);
	cout << ans;
}