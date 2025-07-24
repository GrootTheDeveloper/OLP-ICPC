#include <bits/stdc++.h>
using namespace std;

long long a[100005], dp[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	cout << dp[n];
}