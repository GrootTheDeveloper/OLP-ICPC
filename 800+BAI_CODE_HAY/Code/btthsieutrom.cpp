#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[200005],a[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) dp[i] = max({dp[i-1], dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]});
	cout << dp[n];

}