#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[1000006];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, n; cin >> a >> b >> n;
	dp[0] = a, dp[1] = b;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 2 * dp[i - 2] + 3 * i * i;
		dp[i] %= mode;
	}
	cout << dp[n];
}