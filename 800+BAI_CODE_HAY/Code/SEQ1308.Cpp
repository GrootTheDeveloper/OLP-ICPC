#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[300005][3], rig[300005], a[300005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int cur = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		dp[i][1] = sum - cur;
		cur = min(cur, sum);

	}
	cur = 0, sum = 0;
	for (int i = n; i >= 1; i--)
	{
		sum += a[i];
		rig[i] = sum - cur;
		cur = min(cur, sum); 
	}

	dp[1][2] = max(dp[1][1], dp[1][1] * x);
	for (int i = 2; i <= n; i++)
		dp[i][2] = max({dp[i][1], max(dp[i - 1][1], dp[i - 1][2]) + a[i] * x, a[i] * x});

	int ans = -1e15;
	for (int i = 1; i <= n; i++)
		ans = max({ans, dp[i][2] + rig[i + 1], dp[i][2]});
	cout << ans;
}