#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[10005], cnt[10005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int lim = 0;
	for (int i = 1, ai; i <= n; i++)
	{
		cin >> ai; 
		lim = max(lim, ai);
		cnt[ai]++;
	}
	dp[1] = cnt[1];
	for (int i = 2; i <= lim; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
	cout << dp[lim];
}