#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n; t; --t)
	{
		cin >> n;
		vector <int> dp(n+5,0);
		dp[1] = 1;
		char x; cin >> x;
		for (int i = 2; i <= n; ++i)
		{
			cin >> x;
			if (x == '*') continue;

			dp[i] = (dp[i-1] + (x == '@')) * (dp[i-1] != 0);
			dp[i] = max(dp[i], (dp[i-2] + (x == '@')) * (dp[i-2] != 0));
		}
		int res = 0;
		for (int i = 1; i <= n; i++) res = max(res, dp[i]);
		cout << res - 1 << '\n';

	}
}