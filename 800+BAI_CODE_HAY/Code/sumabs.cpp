#include <bits/stdc++.h>
using namespace std;
#define int long long 

int f[500005][2],a[500005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=2;i<=n;i++)
	{
		f[i][1]=max(f[i-1][1],f[i-1][2]+abs(a[i-1]-1));
		f[i][2]=max(f[i-1][2]+abs(a[i]-a[i-1]),f[i-1][1]+a[i]-1);
	}
	cout << max(f[n][1],f[n][2]);

}