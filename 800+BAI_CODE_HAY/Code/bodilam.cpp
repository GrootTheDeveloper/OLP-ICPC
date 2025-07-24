#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1555][1555],pre[1555][1555],MAX[1555][1555],dp[1555][1555];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	for (int i=1;i<=m;++i) for (int j=1;j<=n;++j)
	{
		cin >> a[i][j];
		pre[i][j]=pre[i][j-1]+a[i][j];
	}

	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=n;++j)
			if (i&1) dp[i][j]=pre[i][j]+MAX[i-1][j-1];
			else     dp[i][j]=pre[i][j]+MAX[i-1][j+1];
		MAX[i][0]=MAX[i][n+1]=INT_MIN;
		if (i&1) for (int j=n;j>=1;--j) MAX[i][j]=max(dp[i][j],MAX[i][j+1]);
		else 	 for (int j=1;j<=n;++j) MAX[i][j]=max(dp[i][j],MAX[i][j-1]);	
	}
	int res=INT_MIN;
	for (int i=1;i<=n;i++) res=max(res,dp[m][i]);
	cout << res;


}