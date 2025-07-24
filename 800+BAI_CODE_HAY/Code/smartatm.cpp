#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[22],f[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++) f[i]=INT_MAX;
	for (int i=1;i<=n;i++)
	for (int j=a[i];j<=m;j++)
		if (f[j-a[i]]!=INT_MAX)
			f[j]=min(f[j],f[j-a[i]]+1);
	if (f[m]==INT_MAX) cout << -1;
	else cout << f[m];
}