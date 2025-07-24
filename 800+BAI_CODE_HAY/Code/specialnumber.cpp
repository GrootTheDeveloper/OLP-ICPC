#include <bits/stdc++.h>
using namespace std;
#define int long long 
int k,m,p,n;
int dp[20][255],a[20];

int calc(int pos, bool lim, int sum, int last)
{
	if (pos==0) return (last==p || sum%m==0);
	if (dp[pos][sum]!=-1 && lim==false) return dp[pos][sum];
	int res=0;
	int mx=(lim? a[pos]:9);
	for (int i=0;i<=mx;i++)
		res+=calc(pos-1,lim && i==mx,sum+i,last=(pos==1? i:-1));
	if (!lim) dp[pos][sum]=res;
	return res;
}

bool check(int x)
{
	n=0;
	while (x) a[++n]=x%10,x/=10;
	return calc(n,true,0,-1)>=k;
}

void solve()
{
	memset(dp,-1,sizeof(dp));
	int l=1,r=1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (check(l-1)) l--;
	while (!check(l))  l++;
	cout << l << '\n'; 
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> k >> m >> p;
		solve();
	}
}