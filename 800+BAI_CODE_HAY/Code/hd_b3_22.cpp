#include <bits/stdc++.h>
using namespace std;
#define int long long 

int f[1000006],a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n=0,mx=0;
	while (true)
	{
		int x; cin >> x;
		if (x) n++,a[n]=x,f[x]++,mx=max(mx,f[x]);
		else break;
	}
	int res=0;
	for (int i=1;i<=n;i++) if (f[a[i]]==mx) res=a[i],f[a[i]]=0;
	cout << res;
}