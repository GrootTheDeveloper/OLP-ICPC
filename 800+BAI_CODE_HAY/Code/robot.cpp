#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1111][1111],a[1111][1111];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("ROBOT.INP","r",stdin);
	//freopen("ROBOT.OUT","w",stdout);
	int m,n; cin >> m >> n;
	for (int i=0;i<=n+1;i++) f[0][i]=f[m+1][i]=INT_MAX;
	for (int j=0;j<=m+1;j++) f[j][0]=f[j][n+1]=INT_MAX;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
	f[1][1]=a[1][1];
	for (int j=2;j<=n;j++) f[1][j]=f[1][j-1]+a[1][j];
	for (int i=2;i<=m;i++)
	for (int j=1;j<=n;j++) f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
	cout << f[m][n] << endl;;
	vector <pair<int,int>> v;
	int x=m,y=n;
	while (1)
	{
		v.push_back({x,y});
		if (x==1 && y==1) break;
		if (f[x-1][y]<f[x][y-1]) x--;else y--;
	}
	while (v.size())
	{
		cout << '(' << v.back().first << ',' << v.back().second << ')';
		v.pop_back();
		if (v.size()) cout << "->";
	}

	
}