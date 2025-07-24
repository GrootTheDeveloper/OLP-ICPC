#include <bits/stdc++.h>
using namespace std;

long long a[555], pre[555], dp[555][555];

long long solve(int l, int r)
{
	if (l == r) return dp[l][r] = 0;
	if (l + 1 == r) return dp[l][r] = a[l] + a[r];
	if (dp[l][r] != -1) return dp[l][r];
	long long ans = 1e15;
	for (int i = l; i < r; i++)
		ans = min(ans, solve(l, i) + solve(i + 1, r) + pre[r] - pre[l - 1]);
	return dp[l][r] = ans;

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(1, n);
}