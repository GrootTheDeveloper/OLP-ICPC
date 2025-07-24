#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[5003][5003],a[5003],b[5003];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int j=1;j<=m;j++) cin >> b[j];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
	else f[i][j]=max(f[i-1][j],f[i][j-1]);
	cout << f[n][m];
}