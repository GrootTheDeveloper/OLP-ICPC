#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int dp[1000005];
main()
{
	int n; cin >> n;
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=min(6LL,i);j++)
			dp[i]=(dp[i]+dp[i-j])%mode;
	}
	cout << dp[n];
}