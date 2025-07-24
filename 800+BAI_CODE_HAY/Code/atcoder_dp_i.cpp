#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define db long double

db dp[3000][3000];
db a[3000];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) dp[i][0] =dp[i - 1][0] * (1 - a[i]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];
	db res = 0;
	for (int i = n / 2 + 1; i <= n; i++) res += dp[n][i];
	cout << fixed << setprecision(10) << res;

}
