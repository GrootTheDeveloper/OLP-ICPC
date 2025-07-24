#include <bits/stdc++.h>
using namespace std;
#define int long long 

int x[100005],w[100005],f[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("mario.inp","r",stdin);
	freopen("mario.out","w",stdout);
	int n,pos,k; cin >> n >> pos >> k;
	for (int i=1;i<=n;i++) cin >> x[i] >> w[i],f[i]=f[i-1]+w[i];
	int t=upper_bound(x+1,x+n+1,pos)-x;
	t--;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int h=k;
		if (x[i]<=pos)
		{
			h-=(pos-x[i])*2;
			if (h)
			{
				int node=upper_bound(x+t+1,x+n+1,pos+h)-x;
				res=max({res,f[node-1]-f[i-1],f[t]-f[i-1]});
			}
		}
		else if (x[i]>pos)
		{
			h-=(x[i]-pos)*2;
			if (h)
			{
				int node=lower_bound(x+1,x+n+1,pos-h)-x;
				res=max({res,f[i]-f[node-1],f[i]-f[t]});
			}
		}
	}
	cout << res;
}