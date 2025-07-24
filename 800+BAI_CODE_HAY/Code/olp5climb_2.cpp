#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int a[N],b[N],sum[N],buf[N],f[N],x,n,q;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i],sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++) cin >> b[i],buf[i]=buf[i-1]+b[i];
	for (int i=1;i<=n;i++)
		f[i]=max(f[i-1],a[i]+buf[i-1]);
	
	while (q--)
	{
		cin >> x;
		int pos=upper_bound(f+1,f+n+1,x)-f-1;
		cout << sum[pos] << '\n';
	}


}