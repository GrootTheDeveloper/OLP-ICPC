#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[555];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("tnv.inp","r",stdin);
	freopen("tnv.out","w",stdout);
	int n,ai; cin >> n;
	for (int i=1;i<=n;i++) cin >> ai, f[ai]++;
	int res=0,val=0;
	for (int i=1;i<=250;i++) if (f[i]>=res) res=f[i],val=i;
	cout << val << ' ' << res; 
}

