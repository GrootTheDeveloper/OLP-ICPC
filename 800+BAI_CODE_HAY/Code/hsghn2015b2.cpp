#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[1111],dp[1111];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CAU2.INP","r",stdin);
	freopen("CAU2.OUT","w",stdout);
	int n,h; cin >> n >> h;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+1;
		for (int j=i-1;j>=1;j--)
		if (a[i]-a[j]<=h) dp[i]=dp[j-1]+1;
	}
	cout << dp[n];
}