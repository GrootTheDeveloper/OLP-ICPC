#include <bits/stdc++.h>
using namespace std;

int a[333][333], col[333][333];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		if (a[i][j] == 0) a[i][j] = -1;
		col[j][i] = col[j][i - 1] + a[i][j];
	}
	int ans = -1e9;
	for (int x = 1; x <= m; x++)
	for (int y = x + 1; y <= m; y++)
	{
		int opt = col[1][y] - col[1][x - 1];
		//ans = max(ans, opt);
		for (int i = 2; i <= n; i++)
		{
			ans = max(ans, (col[i][y] - col[i][x - 1]) + opt);
			opt = max(opt + a[x][i] + a[y][i], col[i][y] - col[i][x - 1]);
		}
	}
	cout << ans;
}
