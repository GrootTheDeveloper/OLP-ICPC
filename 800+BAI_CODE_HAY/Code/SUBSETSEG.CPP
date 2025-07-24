#include <bits/stdc++.h>
using namespace std;
int dp[1001];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	int ans = 1e6;
	for (int i = 1; i <= n; ++i)
	{
		dp[0] = i;
		int ai; cin >> ai;
		for (int x = s; x >= ai; x--)
			if (dp[x - ai] != -1)
				dp[x] = max(dp[x], dp[x - ai]);
		if (dp[s] != -1)
			ans = min(ans, i - dp[s] + 1);
	}
	cout << (ans == 1e6? -1 : ans);
	
}