#include <bits/stdc++.h>
using namespace std;

int dp[1050000][21], x[22], y[22];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		dp[(1 << (i - 1))][i] = 0;
	int MASK = (1 << n) - 1;
	for (int mask = 1; mask <= MASK; mask++)
	{
		for (int p = 1; p <= n; ++p)
		{
			if (!(mask >> (p - 1) & 1)) continue;
			for (int q = 1; q <= n; ++q)
			{
				if (mask >> (q - 1) & 1) continue;
				int newmask = mask | (1 << (q - 1));
				int value = ((__builtin_popcount(mask) & 1) ? dp[mask][p] + abs(x[p] - x[q]) + abs(y[p] - y[q]) : dp[mask][p]);
				dp[newmask][q] = min(dp[newmask][q], value);
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[MASK][i]);
	cout << ans;
}