#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[111][111],a[111][111];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	for (int i=0;i<=101;i++) for (int j=0;j<=101;j++) f[i][j]=INT_MIN;
	int m,n; cin >> m >> n;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) 
		{
			cin >> a[i][j];
			if (j==1) f[i][j]=a[i][j];
		}
	for (int j=2;j<=n;j++)
		for (int i=1;i<=m;i++)
			f[i][j]=max({f[i][j-1],f[i-1][j-1],f[i+1][j-1]})+a[i][j];
	int res=INT_MIN;
	for (int i=1;i<=m;i++) res=max(res,f[i][n]);
	cout << res;
}