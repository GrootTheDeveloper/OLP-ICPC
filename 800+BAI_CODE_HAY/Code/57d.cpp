#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m,n,k,d;

void sub1()
{
	unordered_map <int,int> f;
	int res=0,x,y,v;
	while (k--)
	{
		cin >> x >> y >> v;
		f[y]+=v;
		res=max(res,f[y]);
	}
	cout << res;
}
int a[1111][1111],f[1111][1111];
void sub2()
{
	int x,y,v;
	while (k--)
	{
		cin >> x >> y >> v;
		a[x][y]=v;
	}
	for (int i=1;i<=n;i++) f[1][i]=a[1][i];
	for (int i=2;i<=m;i++) 
	{
		for (int j=1;j<=n;j++)
		for (int z=max(1LL,j-d);z<=min(n,j+d);z++)
			f[i][j]=max(f[i][j],f[i-1][z]+a[i][j]);
	}
	int res=0;
	for (int i=1;i<=n;i++)
		res=max(res,f[m][i]);
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("PRESENT.INP","r",stdin);
	freopen("PRESENT.OUT","w",stdout);
	cin >> m >> n >> k >> d;
	if (d==0) sub1();
	else if (m*n <= 1e6) sub2();
}