#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[200005],a[200005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("BOCBONG.INP","r",stdin);
	freopen("BOCBONG.OUT","w",stdout);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i],f[i]=f[i-1]+a[i];
	double res=-1e18;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i-k;j++)
		res=max(res,(double)(f[i]-f[j])/(i-j));
	cout << fixed << setprecision(3) << res;
}