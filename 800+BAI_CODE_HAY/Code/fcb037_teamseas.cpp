#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2005][2005],f[10000];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int m,n; cin >> n >> m;
	for (int i=1;i<=n;i++) 
	for (int j=1;j<=m;j++) cin >> a[i][j];
	int cnt=0,res=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		int val=a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
		f[val]++;
		if (f[val]>cnt) res=val,cnt=f[val];
		else if (f[val]==cnt) res=max(res,val);
	}
	cout << res;
}