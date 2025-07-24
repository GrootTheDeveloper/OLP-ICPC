#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,f[1000006],a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("chumden.inp","r",stdin);
	freopen("chumden.out","w",stdout);
	cin >> n >> k;
	int cnt=0,res=0;
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		cnt+=(a[i]&1);
		if (cnt>=k) res+=f[cnt-k];
		f[cnt]++;
	}
	cout << res;
}