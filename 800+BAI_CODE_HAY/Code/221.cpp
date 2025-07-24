#include <bits/stdc++.h>
using namespace std;
//#define int long long 

int a[22][22], dp[1200000][22];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int MASK = (1 << n) - 1;
	for (int i = 0; i <= MASK; i++)
		fill(dp[i], dp[i] + n + 1, -1000000000);
	dp[0][0] = 0;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int q = 1; q <= n; q++)
		{
			if ((mask >> (q - 1) & 1)) continue;
			for (int p = 0; p <= n; p++)
			{
				if (p == q) continue;
				int cnt = __builtin_popcount(mask);
				int newmask = mask | (1 << (q - 1));
				if (cnt & 1) 
					dp[newmask][q] = max(dp[newmask][q], dp[mask][p] + a[p][q]);
				else dp[newmask][q] = max(dp[newmask][q], dp[mask][p]);
			}
		}
	}
	int ans = -1e9;
	int fullmask = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[fullmask][i]);
	cout << ans;
}