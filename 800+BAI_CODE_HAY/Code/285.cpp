#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[300000];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	int sum = 0;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int wi, vi; cin >> wi >> vi;
		sum += vi;
		for (int j = sum; j >= vi; j--)
			{
				if (dp[j - vi] != -1)
				{
					if (dp[j] == -1) dp[j] = dp[j - vi] + wi;
					else dp[j] = min(dp[j], dp[j - vi] + wi);
				}
			}
	}
	int res = 0;
	for (int i = 1; i <= sum; i++) 
		if (dp[i] <= s && dp[i] != -1) res = i;
	cout << res;
}