#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long dp[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[1] = max(a[1], 0);
	dp[2] = max({a[1], a[2], a[1] + a[2], 0});
	for (int i = 3; i <= n; i++)
		dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i] + a[i - 1]});
	cout << dp[n];

}