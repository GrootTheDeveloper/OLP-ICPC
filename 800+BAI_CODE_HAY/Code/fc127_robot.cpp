#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int up[10004][64];
short a[111][111];
int zip(int x, int y)
{
	return (x - 1) * n + y;
}
pair<int,int> ex(int k)
{
	return {(k - 1) / n + 1, (k - 1) % n + 1};
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		int id = zip(i, j);
		int x = i + dx[a[i][j]], y = j + dy[a[i][j]];
		up[id][0] = (x >= 1 && x <= m && y >= 1 && y <= n? zip(x, y) : id);
	}

	int lim = m * n;
	for (int i = 1; i <= 60; i++)
	for (int u = 1; u <= lim; u++)
		up[u][i] = up[up[u][i - 1]][i - 1];

	int k; cin >> k;
	int u = 1;
	int lo = log2(k) + 1;
	for (int i = lo; i >= 0; i--)
		if (k >> i & 1) u = up[u][i];
	pair<int,int> ans = ex(u);
	cout << ans.first << ' ' << ans.second;
}