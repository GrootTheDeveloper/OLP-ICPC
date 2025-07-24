#include <bits/stdc++.h>
using namespace std;
#define int long long 

int lim;
int cnt[100005];
int dp[100005];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i = 1,ai; i <= n; i++) cin >> ai, cnt[ai] ++, lim = max(lim,ai);
	
	for (int i = 1; i <= lim; i++)  
		if (cnt[i])
			dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
		else dp[i] = dp[i-1];
	cout << dp[lim];
}