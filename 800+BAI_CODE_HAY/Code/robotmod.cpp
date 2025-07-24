#include <bits/stdc++.h>
using namespace std;
#define int long long 

string dp[111][111];

string comp(string a, string b)
{
	while (a.size()<b.size()) a="0"+a;
	while (b.size()<a.size()) b="0"+b;
	string res="";
	int nho=0;
	for (int i=a.size()-1;i>=0;i--)
	{
		int k=(a[i]-'0')+(b[i]-'0')+nho;
		res=to_string(k%10)+res;
		nho=k/10;
	}
	if (nho) res=to_string(nho)+res;
	return res;
}
int a[111][111];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("robot.inp","r",stdin);
	freopen("robot.out","w",stdout);
	int n,m;cin >> n >> m;
	for (int i=1,x,y;i<=m;i++)
	{
		cin >> x >> y;
		a[x][y]=1;
	}
	for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) dp[i][j]="0";
	dp[0][1]="1";
	for (int i=1; i<=n ; ++i) for (int j=1; j<=n; ++j)
		if (!a[i][j])
			dp[i][j]=comp(dp[i-1][j],dp[i][j-1]);
	cout << dp[n][n];
}