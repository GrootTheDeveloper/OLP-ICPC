#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m,x,c[55],h[55],size_max;
const int MAX=1e12;

void solve()
{
	int sum=0;
	vector <int> dp(size_max+5,MAX);
	dp[0]=0;
	for (int i=1;i<=m;i++)
	{
		sum+=h[i];
		for (int j=sum;j>=h[i];j--)
			if (dp[j-h[i]]!=MAX && dp[j-h[i]]+c[i]<=x*(i-1))
				dp[j]=min(dp[j],dp[j-h[i]]+c[i]);

	}
	for (int i=sum;i>=0;i--) if (dp[i]!=MAX) return cout << i << '\n',void();
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> m >> x;
		for (int i=1;i<=m;i++)
		{
			cin >> c[i] >> h[i];
			size_max+=h[i];
		}
		solve();
	}
}