#include <bits/stdc++.h>
using namespace std; 
#define int long long 
bool getbit(int x, int k)
{
	return (x >> k) & 1;
}

void solve()
{
	int n, k; cin >> n >> k;
	vector<vector<int>> dp((1 << n) + 1, vector<int> (n + 1, 0));
	int MASK = (1 << n) - 1;
	dp[0][0] = 1;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (getbit(mask, q - 1)) continue;
			for (int p = 0; p <= n; p++)
			{
				if (p != 0 && abs(q - p) > k) continue;
				int newmask = mask | (1 << (q - 1));
				dp[newmask][q] += dp[mask][p];
			}
		}
	}
	int fullmask = (1 << n) -1;
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += dp[fullmask][i];
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}