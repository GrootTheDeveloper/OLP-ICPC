#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=1e12;
int a[101][10001];
int n,m,k,d;
int calc(int idx)
{
	vector <int> dp(n+2,MAX);
	dp[1]=a[idx][1];
	for (int i=2;i<=n;i++)
	{
		for (int j=i-1;j>=max(1ll,i-d-1);j--)
			dp[i]=min(dp[i],dp[j]+a[idx][i]);
	}
	return dp[n];

}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> m >> n >> k >> d;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j],a[i][j]++;
	vector <int> v;
	for (int i=1;i<=m;i++) v.push_back(calc(i));
	
	int sum=0,res=MAX;
	for (int i=0;i<m;i++)
	{
		sum+=v[i];
		if (i>=k-1) res=min(res,sum),sum-=v[i-k+1];
	}
	cout << res;

}