#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[2002], dp[2002][2002];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[i][n + 1] = dp[i - 1][n + 1] + i * a[i];
	for (int i = n; i >= 1; i--) dp[0][i] = dp[0][i + 1] + (n - i + 1) * a[i];
	for (int i = 1; i <=n; i++)
		for (int j = n; j > i; j--)
			dp[i][j] = max({dp[i - 1][j] + a[i] * (i + n - j + 1), dp[i][j + 1] + a[j] * (i + n - j + 1)});
	int res = 0;
	for (int i = 0; i <= n; i++) res = max(res, dp[i][i + 1]);
	cout << res;
}