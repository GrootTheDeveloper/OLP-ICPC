#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[500005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seqd.inp","r",stdin);
	freopen("seqd.out","w",stdout);
	int n,k,ai; cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		int c=trunc(sqrt(ai));
		f[i]=f[i-1]+min(abs(ai-c*c),abs(ai-(c+1)*(c+1)));
	}
	int res=f[k];
	for (int i=k+1;i<=n;i++) res=min(res,f[i]-f[i-k]);
	cout << res;
}