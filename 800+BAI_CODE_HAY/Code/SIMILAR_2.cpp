#include <bits/stdc++.h>
using namespace std;

int dp[1111][1111], a[1111], b[1111], pre[1111];
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
		dp[i][i] = (a[i] == b[i]);
	}

	for (int len = 2; len <= n; len++)
	for (int i = 1; i + len - 1 <= n; i++)
	{
		int j = i + len - 1;
		dp[i][j] = dp[i + 1][j - 1] + (a[i] == b[j]) + (a[j] == b[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++)
		ans = max(ans, dp[i][j] + pre[i - 1] + (pre[n] - pre[j]));
	cout << ans;

}