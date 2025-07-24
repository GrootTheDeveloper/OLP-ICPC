#include <bits/stdc++.h>
using namespace std;

int a[3333][3333], dp[3333][3333];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];

	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = dp[1][i - 1] + a[1][i];
		dp[2][i] = max(dp[1][i], dp[2][i - 1]) + a[2][i];
		dp[3][i] = max(dp[2][i], dp[3][i - 1]) + a[3][i];                
	}
	for (int i = 4; i <= m; i++)
	for (int j = 2; j <= n; j++)
	{ 
		dp[i][j] = dp[i][j - 1] + a[i][j];
		dp[i][j] = max({dp[i][j], dp[i - 1][j - 1] + a[i - 1][j] + a[i][j], dp[i - 2][j - 1] + a[i - 1][j] + a[i - 2][j] + a[i][j]});
	}
	cout << dp[m][n];
}