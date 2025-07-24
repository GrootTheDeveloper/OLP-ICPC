#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e12;
int m,x;
int c[55],h[55],lim;

void solve()
{
	vector <int> dp(lim+1,MAX);
	dp[0]=0;
	for (int i=1;i<=m;i++)
	{	
		for (int j=lim;j>=h[i];j--) 
			if (dp[j-h[i]]!=MAX && dp[j-h[i]]+c[i]<=x*(i-1)) dp[j]=min(dp[j],dp[j-h[i]]+c[i]);
	}
	for (int i=lim;i>=0;i--) if (dp[i]!=MAX) return cout << i << '\n',void();
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("NOBITA.INP","r",stdin);
	freopen("NOBITA.OUT","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		cin >> m >> x;
		for (int i=1;i<=m;i++) cin >> c[i] >> h[i],lim+=h[i];
		solve();
	}
}