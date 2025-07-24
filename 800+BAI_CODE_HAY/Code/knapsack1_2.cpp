#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,w; cin >> n >> w;
	vector <int> dp(w + 1, INT_MIN);
	dp[0]=0;
	for (int l = 1,wi,vi; l <= n; ++l)
	{
		cin >> wi >> vi;
		for (int i = w; i >= wi; --i)
			if (dp[i - wi] != INT_MIN) dp[i] = max(dp[i-wi] + vi, dp[i]);
	}
	for (int i = 1; i <= w; i++) dp[i] = max(dp[i-1],dp[i]);
	cout << dp[w];
}