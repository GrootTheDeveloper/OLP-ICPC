#include <bits/stdc++.h>
using namespace std;
int dp[1000], a[1000], b[1000];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int last = 0;
	for (int i = 1; i <= n; i++)
	{
		while (a[i] - a[last + 1] >= k) 
			++last;
		dp[i] = max(dp[i - 1], dp[last] + b[i]);
	}
	cout << dp[n];
}