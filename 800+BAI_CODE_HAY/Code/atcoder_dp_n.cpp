#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[444][444], pre[444], a[444];

int calc(int l, int r)
{
	if (l == r) return dp[l][r] = 0;
	if (r - l == 1) return dp[l][r] = a[l] + a[r];
	if (dp[l][r] != -1) return dp[l][r];
	int ans = 1e15;
	for (int i = l; i < r; i++)
		ans = min(ans, calc(l, i) + calc(i + 1, r) + pre[r] - pre[l - 1]);
	return dp[l][r] = ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	memset(dp, -1, sizeof(dp));
	cout << calc(1, n);
}