#include <bits/stdc++.h>
using namespace std;
#define int long long 

int c[10000],h[10000],w[10000],dp[10000];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,p,q; cin >> n >> p >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> c[i] >> w[i] >> h[i];
		dp[i]=dp[i-1]+h[i];
		for (int j=i-1,mc=c[i],mw=w[i],lim=h[i];j>=1;j--)
		{
			mc+=c[j];mw+=w[j];
			if (mc<=p && mw<=q)
			{
				lim=max(lim,h[j]);
				dp[i]=min(dp[i],dp[j-1]+lim);
			}	
			else break;
		}
	}
	cout << dp[n];
}