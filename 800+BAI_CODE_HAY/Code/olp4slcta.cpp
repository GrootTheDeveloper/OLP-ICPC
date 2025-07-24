#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[5555],dp[5555],mode=1e9+7;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	for (int i=1;i<=n;i++) f[i]=f[i-1]+((s[i-1]=='1')? 1:-1);
	dp[0]=1;
	for (int i=1;i<=n;i++)
	for (int j=i;j>=1;j--)
	if (abs(f[i]-f[j-1])<=k) dp[i]=(dp[i]+dp[j-1])%mode;
	cout << dp[n];
}