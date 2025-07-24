#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q,res,l,r,a[1000006];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("TT.INP","r",stdin);
	freopen("TT.OUT","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i],res+=a[i];
	while (q--)
	{
		cin >> l >> r;
		for (int i=l;i<=r;i++) 
		{
			res=res-a[i]+a[i]/2;
			a[i]=a[i]/2;
		}
		cout << res << '\n';
	}
}