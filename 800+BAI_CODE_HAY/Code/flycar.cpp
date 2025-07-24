#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k, a[404];
int MAX[404][404], pre[404][404];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		MAX[i][i] = a[i];
		pre[i][i] = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			MAX[i][j] = max(MAX[i][j-1], a[j]);
			pre[i][j] = pre[i][j - 1] + a[j];
		}
	}
	vector <vector<int>> dp(n + 1, vector<int> (n + 1, (int)1e18));
	for (int i = 1; i <= n; i++) dp[0][i] = MAX[1][i]*i - pre[1][i];
	for (int change = 1; change <= k; change ++)
		for (int i = change; i <= n; i++)
			for (int j = i; j >= change; j--)
				dp[change][i] = min(dp[change][i], dp[change - 1][j - 1] + MAX[j][i]*(i - j + 1) - pre[j][i]);
	cout << dp[k][n];

}