#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e15;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, w; cin >> n >> w;
	vector <int> dp(n * 1000 + 5, inf);
	int sum = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int wi, vi; cin >> wi >> vi;
		sum += vi;
		for (int i = sum; i >= vi; i--)
			if (dp[i - vi] != inf)
				dp[i] = min(dp[i], dp[i - vi] + wi);
	}
	int res = 0;
	for (int i = 1; i <= sum; i++)
		if (dp[i] <= w) res = i;
	cout << res;

}