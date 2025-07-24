#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=-1e9;
int a[111][111],dp[111][111];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,x; cin >> n >> x;
	for (int i=1; i <= n; ++i)
		for (int j=1; j <= x; ++j)
			cin >> a[i][j];
	for (int i=1;i<=n;i++) for(int j=1;j<=x;j++) dp[i][j]=MAX;
	dp[0][0]=0;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=x; ++j)
			for (int z=x; z>=j; --z)
				if (dp[i-1][z-j]!=MAX) dp[i][z]=max({dp[i-1][z],dp[i][z],dp[i-1][z-j]+a[i][j]});
	cout << dp[n][x];
		

}