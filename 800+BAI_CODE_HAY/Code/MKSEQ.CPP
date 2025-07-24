#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	memset(dp, 0x4f, sizeof(dp));
	dp[0] = 0;
	int sum = 0, ans = -1e15;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		sum += ai;
		ans = max(ans, sum - dp[i % q]);
		dp[i % q] = min(dp[i % q], sum);

	}
	cout << ans;
}