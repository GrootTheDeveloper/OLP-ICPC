#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int dp[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	dp[0] = 1;
	for (int _ = 1; _ <= n; ++_)
	{
		int c; cin >> c;
		for (int i = c; i <= x; ++i)
			dp[i] = (dp[i] + dp[i - c]) % mode;
	}
	cout << dp[x];
}