#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = -1e9;
int dp[333][333][333], a[333][333];
void maxize(int &a, int b)
{
	a = max(a, b);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, c; cin >> n >> c;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];

	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++)
	for (int z = 0; z <= n; z++)
		dp[i][j][z] = inf;
	
	dp[1][0][0] = dp[0][1][0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		for (int x = 0; x <= min(c, n); x++)
		{
			if (dp[i - 1][j][x] != inf) maxize(dp[i][j][x], dp[i - 1][j][x] + a[i][j]);
			if (dp[i][j - 1][x] != inf) maxize(dp[i][j][x], dp[i][j - 1][x] + a[i][j]);
			if (dp[i - 1][j - 1][x] != inf && x < c) maxize(dp[i][j][x + 1], dp[i - 1][j - 1][x] + a[i][j]);
		}
	}
	int ans = inf + inf;
	for (int i = 0; i <= min(c, n - 1); i++)
		maxize(ans, dp[n][n][i]);
	cout << ans;
}