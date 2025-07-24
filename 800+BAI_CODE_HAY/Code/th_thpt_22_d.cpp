#include <bits/stdc++.h>
using namespace std;
#define int long long 


string solve()
{
	int n,k; cin >> n >> k;
	int gmax=0,s=0,ai;
	for (int i=1;i<=n;i++) cin >> ai,s+=ai,gmax=max(gmax,ai);
	if (s%k!=0 || s/k<gmax) return "NO"; 
	else return "YES";
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("EQLARRAY.INP","r",stdin);
	freopen("EQLARRAY.OUT","w",stdout);
	int q; cin >> q;
	while(q--) cout << solve() << '\n';
}