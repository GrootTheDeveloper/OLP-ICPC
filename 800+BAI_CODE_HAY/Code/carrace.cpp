#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[100005][201];
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][m] = mx;
		for (int j = m - 1; j >= 0; j--)
			dp[i][j] = dp[i - 1][j + 1] + a[i];
		mx = dp[i][m];
		for (int j = 0; j <= m; j++) mx = max(mx, dp[i][j]);
	}
	cout << dp[n][m];
}