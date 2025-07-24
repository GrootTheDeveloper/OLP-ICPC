#include <bits/stdc++.h>
using namespace std; 
//#define int long long  
int a[22];
int dp[2][1200000][21];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, w; cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int MASK = (1 << n) - 1;
	dp[0][0][0] = 1;
	dp[1][0][0] = 0;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int q = 1; q <= n; q++)
		{
			if ((mask >> (q -1) & 1)) continue;
			for (int p = 0; p <= n; p++)
			{
				int newmask = mask | (1 << (q - 1));
				if (dp[0][mask][p] == 0) continue;
				
				if (dp[0][newmask][q] == 0)
				{
					dp[0][newmask][q] = dp[0][mask][p] + (dp[1][mask][p] + a[q] > w);
					dp[1][newmask][q] = (dp[1][mask][p] + a[q] > w? a[q] : dp[1][mask][p] + a[q]);
				}else
				{
					if (dp[1][mask][p] + a[q] > w)
					{
						if (dp[0][newmask][q] > dp[0][mask][p] + 1)
						{
							dp[0][newmask][q] = dp[0][mask][p] + 1;
							dp[1][newmask][q] = a[q];
						} else if (dp[0][newmask][q] == dp[0][mask][p] + 1)
							dp[1][newmask][q] = min(dp[1][newmask][q], a[q]); 
					} else
					{
						if (dp[0][newmask][q] > dp[0][mask][p])
						{
							dp[0][newmask][q] = dp[0][mask][p];
							dp[1][newmask][q] = dp[1][mask][p] + a[q];
						} else if (dp[0][newmask][q] == dp[0][mask][p])
							dp[1][newmask][q] = min(dp[1][newmask][q], dp[1][mask][p] + a[q]);
					}
				}
			}
		}
	}
	int ans = n;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[0][MASK][i]);
	cout << ans;
}