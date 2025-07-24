#include <bits/stdc++.h>
using namespace std;
#define int long long
int heso[5] = {5, 1, -2, 3, -4};
int dp[1111][1111], a[1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= 5 * k; i++)
		dp[0][i] = -1e15;
	k *= 5;
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 1][1], a[i]);
		for (int j = 2; j <= k; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i] * heso[j % 5]);
	}
	cout << dp[n][k];
}