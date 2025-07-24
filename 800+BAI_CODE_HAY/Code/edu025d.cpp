#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1005][1005],dif[100005];

void init()
{
	for (int i=2;i<=1e5;i++)
		for (int j=i;j<=1e5;j+=i) dif[j]++;
	
}
void solve()
{
	int m,n; cin >> m >> n;
	vector <vector<int>> f(m+3,vector<int> (n+3,100000));
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j],a[i][j]=dif[a[i][j]];
	
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
	{
		if (i==1 && j==1) f[i][j]=a[i][j];
		else f[i][j]=min(f[i-1][j],f[i][j-1]) + a[i][j];
	}
	cout << f[m][n] << '\n';

}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("CHIPHI.INP","r",stdin);
	freopen("CHIPHI.OUT","w",stdout);
	int t; cin >> t;
	init();
	while (t--) solve();
	


	

}