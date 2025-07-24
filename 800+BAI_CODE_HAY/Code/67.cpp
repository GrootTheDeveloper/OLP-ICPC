#include <bits/stdc++.h>
using namespace std;

long long a[555][555], col[555][555];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		col[j][i] = col[j][i - 1] + a[i][j];
	}

	long long ans = -1e9;
	for (int x = 1; x <= m; x++)
	for (int y = x; y <= m; y++)
	{
		long long cur_sum = 0, cur_min = 0;
		for (int i = 1; i <= n; i++)
		{
			cur_sum += col[i][y] - col[i][x - 1];
			ans = max(ans, cur_sum - cur_min);
			cur_min = min(cur_min, cur_sum);
		}
	}
	cout << ans;
}