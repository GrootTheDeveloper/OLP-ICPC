#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[555][555],f[555][555],cnt[10];

int calc(int n)
{
	return n*(n-1)/2;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++)
	{
		cin >> a[i][j];
		a[i][j]%=9;
		f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
	}
	int res=0;
	for (int x=1;x<=m;x++) for (int y=x;y<=m;y++)
	{
		memset(cnt,0,sizeof(cnt));
		cnt[0]=1;
		for (int u=1;u<=n;u++)
			cnt[(f[y][u]-f[x-1][u])%9]++;
		for (int i=0;i<=8;i++)
			res+=calc(cnt[i]);
	}
	cout << res;
}