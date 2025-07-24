#include <bits/stdc++.h>
using namespace std;

int a[1111], b[1111], dp[1111][1111], pre[1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + (a[i] == b[i]);
		dp[i][i] = pre[i] - pre[i - 1];
	}
	for (int i = 1; i < n; i++)
		dp[i][i + 1] = (a[i] == b[i + 1]) + (b[i] == a[i + 1]);
	for (int len = 3; len <= n; len++)
	{
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			dp[i][j] = dp[i + 1][j - 1] + (a[j] == b[i]) + (a[i] == b[j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++)
		ans = max(ans, dp[i][j] + pre[i - 1] + (pre[n] - pre[j]));
	cout << ans;
}