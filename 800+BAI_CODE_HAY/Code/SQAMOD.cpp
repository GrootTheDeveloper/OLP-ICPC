#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[10005][3],a[10005],n;
string s;
int calc(int i, bool lim, int sum)
{
	if (i<1) return sum==0;
	if (lim==0 && dp[i][sum]>=0) return dp[i][sum];
	int kq=0;
	int mx=(lim? a[i]:9);
	for (int c=0;c<=mx;c++)
		kq+=calc(i-1,lim && c==mx,(sum+c*c)%3);
	if (!lim) dp[i][sum]=kq;
	return kq;
}
int G(string x)
{
	n=0;
	int t=0;
	for (int i=(int)s.size()-1;i>=0;i--)
	{
		n++;
		a[n]=(s[i]-'0');
		t+=a[n]*a[n];
	}
	return calc(n,true,0)-(t%3==0);
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		cout << G(s) << '\n';
	}
}