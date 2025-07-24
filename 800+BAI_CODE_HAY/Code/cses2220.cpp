#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[20][10],n,a[20];


int calc(int pos, bool lim, int k)
{
	if (pos==1) return 9;
	if (dp[pos][k]!=-1 && lim==false) return dp[pos][k];
	int res=0;
	int mx=(lim? a[pos]:9);
	for (int c=0;c<=mx;c++)
	{
		int cnt=calc(pos-1,lim && c==mx,c);
		if (k!=c) res+=cnt;
	}
	if (lim==false) dp[pos][k]=res;
	return res;
}

int solve(int x)
{
	n=0;
	while (x) a[++n]=x%10,x/=10;
	return calc(n,true,0);
}

main()
{
	int a,b; cin >> a >> b;
	memset(dp,-1,sizeof(dp));
	cout << solve(b)-solve(a-1);
}