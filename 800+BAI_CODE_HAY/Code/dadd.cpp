#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[3003];
signed main()
{
	int n, W; cin >> n >> W;
	while (n--)
	{
		int w, v, b, a; cin >> w >> v >> b >> a;
		for (int i = W; i >= w; i--)
		for (int j = 1; j * w <= i; j++)
			dp[i] = max(dp[i], dp[i - j * w] + v * j - a * j * j + b);
	}
	int ans = 0;
	for (int i = 1; i <= W; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}