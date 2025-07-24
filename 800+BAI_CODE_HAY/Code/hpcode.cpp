#include <bits/stdc++.h>
using namespace std;
#define int long long 
int b[100005];

void solve()
{
	int n; cin >> n;
	int maxa=0,mina=INT_MAX,maxb=0,minb=INT_MAX,ai;
	unordered_map <int,bool> f;
	for (int i=1;i<=n;i++) cin >> ai,maxa=max(ai,maxa),mina=min(ai,mina),f[ai]=true;
	for (int i=1;i<n;i++) cin >> b[i],maxb=max(maxb,b[i]),minb=min(b[i],minb);
	
	int res=INT_MAX;
	int k=minb-mina;
	bool check=true;
	for (int i=1;i<n;i++) if (!f[b[i]-k]) {check=false;break;}
	if (check && k>0) res=k;
	k=maxb-maxa;check=true;
	for (int i=1;i<n;i++) if (!f[b[i]-k]) {check=false;break;}
	if (check && k>0) res=min(res,k);
	cout << res << '\n';
}




main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}