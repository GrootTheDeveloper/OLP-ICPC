#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[444][444],pre[444],sum[444][444],a[444];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i-1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		f[i][i] = a[i];
		sum[i][i] = a[i];
		for (int j = i + 1; j <= n; j++) f[i][j] = max(a[j],f[i][j-1]), sum[i][j] = pre[j] - pre[i-1];
	}
	vector<vector<int>> dp(k+5,vector<int> (n+5,(int)1e15));
	
	for (int i = 1; i <= n; i++)
		dp[0][i] = f[1][i] * i - sum[1][i];
	
	for (int i = 1; i <= k; ++i)
		for (int j = n; j >= i + 1; j--)
			for (int x = j; x >= i + 1; x--)
				dp[i][j] = min(dp[i][j],dp[i - 1][x - 1] + f[x][j]*(j - x + 1) - sum[x][j]);
	cout << dp[k][n];
	
}