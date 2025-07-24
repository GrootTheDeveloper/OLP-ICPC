#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[1000006],cnt[10000006],a[1000006];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int m; cin >> m;
	for (int i=1;i<=m;i++) cin >> a[i],f[a[i]]=1;
	int n,x,res=0; cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> x;
		int t=x,nod=x;
		while (t && nod<1e6)
		{
			if (f[nod]) res++,f[nod]=0;
			if (!cnt[nod]) cnt[nod]=1,t--;
			nod+=x;
		}
	}
	cout << res;
}