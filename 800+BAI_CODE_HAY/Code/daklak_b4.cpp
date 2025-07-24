#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005],f[100005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	for (int i=2;i<=n;i+=2)
	{
		f[i]=max(f[i],f[i-2]+a[i-1]);
		if (i-4>=0) f[i]=max(f[i],f[i-4]+a[i-3]+a[i-2]);
		if (i-6>=0) f[i]=max(f[i],f[i-6]+a[i-5]+a[i-4]+a[i-3]);
	}
	if (n%2==0)
		cout << max({f[n],
					f[n-4]+a[n-3]+a[n-2]+a[n-1],
					f[n-2]+a[n-1]+a[n]});
	else cout << max(f[n-1]+a[n],f[n-3]+a[n]+a[n-1]+a[n-2]);
}