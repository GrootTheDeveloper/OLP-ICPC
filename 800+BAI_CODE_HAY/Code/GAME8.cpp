#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[20][20];
int dp[70000][20];
void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int MASK = (1 << n) - 1;
	for (int i = 0; i <= MASK; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 1e12;
	dp[0][0] = 0;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (mask >> (q - 1) & 1) continue;
			int cnt = __builtin_popcount(mask);
			for (int p = 0; p <= n; p++)
			{
				if (p == q) continue;
				int newmask = mask | (1 << (q - 1));
				dp[newmask][q] = min(dp[newmask][q], dp[mask][p] + a[cnt + 1][q]);
			}
		}
	}
	int ans = 1e12;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[MASK][i]);
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--)
		solve();
}