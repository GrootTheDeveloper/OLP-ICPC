#include <bits/stdc++.h>
using namespace std;
#define int long long 
int p5[155], p2[155];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		while (ai % 2 == 0) p2[i]++, ai/=2;
		while (ai % 5 == 0) p5[i]++, ai/=5;
	}
	vector<vector<int>> dp(k + 1, vector<int> (25 * n + 1, -1));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = k; j >= 1; j--)
			for (int z = n * 25; z >= p5[i]; z--)
			{
				if (dp[j - 1][z - p5[i]] != -1)
					dp[j][z] = max(dp[j][z], dp[j - 1][z - p5[i]] + p2[i]);
			}
	int ans = 0;
	for (int i = 1; i <= n * 25; i++)
		ans = max(ans, min(dp[k][i], i));
	cout << ans;
}