#include <bits/stdc++.h>
using namespace std;

int a[1555][1555], lef[1555], top[1555];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n, k; cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}

	for (int i = k; i <= m; i++)
	for (int j = k; j <= n; j++)
	{
		int val = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
		lef[j] = max(lef[j], val);
		top[i] = max(top[i], val);
	}
	for (int i = k; i <= m; i++)
		top[i] = max(top[i - 1], top[i]);
	for (int i = k; i <= n; i++)
		lef[i] = max(lef[i - 1], lef[i]);

	int ans = 0;
	for (int i = k; i <= m; i++)
	for (int j = k; j <= n; j++)
	{
		int val = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
		ans = max({ans, val + top[i - k], val + lef[j - k]});
	}
	cout << ans;
}