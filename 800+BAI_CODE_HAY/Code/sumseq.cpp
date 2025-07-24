#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[100005],n,ai,u,v,x,q;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> x >> q;
	for (int i=1;i<=n;i++) cin >> ai, f[i]=f[i-1]+ai;
	int res=0;
	while (q--)
	{
		cin >> u >> v;
		res+=(f[v]-f[u-1]<=x);
	}
	cout << res;
}