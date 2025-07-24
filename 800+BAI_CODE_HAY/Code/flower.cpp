#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1001][1001],f[1001][1001];
bool cnt[1001][1001];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int m,n; cin >> m >> n;
	memset(a,-1,sizeof(a));
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)	
		cin >> a[i][j];
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
	{
		if (i==1 && j==1) f[i][j]=a[1][1],cnt[1][1]=(a[1][1]>=0);
		else
		{
			if (a[i][j]>=0)
			{
				if (cnt[i][j-1]) f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]),cnt[i][j]=true;
				if (cnt[i-1][j]) f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]),cnt[i][j]=true;
			}
		}
	}
	if (cnt[m][n]==0) cout << -1;
	else cout << f[m][n];

}