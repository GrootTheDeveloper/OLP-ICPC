#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first 
#define id second

int n,k,dp[400005],pre[400005],a[400005];
priority_queue <ii,vector<ii>,greater<ii>> q;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
		q.push({a[i],i});
		if (i>=k)
		{
			while (q.top().id<=i-k) q.pop();
			ii m=q.top();
			dp[i]=max({dp[i-1],dp[i-k]+pre[i]-pre[i-k+1]});
			if (i>k) dp[i]=max(dp[i],dp[i-k-2]+pre[i]-pre[i-k]-a[m.id]);
		}
		else dp[i]=pre[i];
	}
	cout << dp[n];
}