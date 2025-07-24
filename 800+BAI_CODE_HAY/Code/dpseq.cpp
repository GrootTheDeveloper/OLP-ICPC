#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[10005],a[10005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	int ans=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		for (int j=i-1;j>=max(0LL,i-k);j--) f[i]=max(f[i],f[j]+a[i]);
		ans=max(ans,f[i]);
	}
	cout << ans;
}