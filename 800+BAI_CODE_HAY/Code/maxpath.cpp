#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[111][111],f[111][111];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> m >> n;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
	for (int j=1;j<=n;j++)
		for (int i=1;i<=m;i++)
			f[i][j]=max({f[i-1][j-1],f[i][j-1],f[i+1][j-1]})+a[i][j];
	int res=0;
	for (int i=1;i<=m;i++) res=max(res,f[i][n]);
	cout << res;
}