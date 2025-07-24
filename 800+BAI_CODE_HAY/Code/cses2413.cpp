#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int dp[1000006],p[1000006];
void init()
{
	p[1]=1;
	int pre=1;
	for (int i=2;i<=1e6;i++)
	{
		p[i]=(pre+1)%mode;
		pre=(pre+p[i])%mode;
	}
	dp[1]=2;
	int last=2;
	for (int i=2;i<=1e6;i++)
	{
		dp[i]=(p[i]*p[i]+last)%mode;
		last=(last+dp[i])%mode;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t; cin >> t;
	init();
	while (t--)
	{
		int x;cin >> x;
		cout << dp[x] << '\n';
	}
}