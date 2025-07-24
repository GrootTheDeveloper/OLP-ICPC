#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[111][666];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,a,b; cin >> n >> a >> b;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int c=1;c<=6;c++)
			for (int j=c;j<=6*n;j++)
				dp[i][j]+=dp[i-1][j-c];
	int omega=0,bc=0;
	for (int i=1;i<=6*n;i++)
	{
		//if (dp[n][i]) omega+=dp[n][i];
		//if (i>=a && i<=b) bc+=dp[n][i];
		cout << dp[n][i] << ' ';
	}
	//cout << fixed << setprecision(6) << (double)bc/(double)omega;
}