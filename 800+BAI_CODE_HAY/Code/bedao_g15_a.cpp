#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[111][111],f[111][111];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> m >> n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) cin >> a[i][j];
	for (int i=2;i<=m-1;i++)
		for (int j=2;j<=n-1;j++)
		if (a[i-1][j] && a[i+1][j] && a[i][j-1] && a[i][j+1])
		{
			int k=min({a[i-1][j]-f[i-1][j],a[i+1][j]-f[i+1][j],a[i][j-1]-f[i][j-1],a[i][j+1]-f[i][j+1]});
			a[i][j]+=k;
			f[i][j]=k;
			a[i-1][j]-=k;
			a[i+1][j]-=k;
			a[i][j-1]-=k;
			a[i][j+1]-=k;
		}
	
	for (int i=1;i<=m;i++) 
	{
		for (int j=1;j<=n;j++) cout << f[i][j] << ' ';
		cout << '\n';
	} 
}