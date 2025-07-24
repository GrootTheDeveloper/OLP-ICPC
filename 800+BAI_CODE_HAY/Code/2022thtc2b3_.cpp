#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[1000005],fimax[1000005],fimin[1000005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("BOBASO.INP","r",stdin);
	freopen("BOBASO.OUT","w",stdout);
	int n; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		fimax[i]=max(fimax[i-1],a[i]);
	}
	fimin[n+1]=INT_MAX;
	for (int i=n;i>=1;i--)
		fimin[i]=min(fimin[i+1],a[i]);
	int res=INT_MIN;
	for (int i=2;i<n;i++)
		res=max(res,3*fimax[i-1]+2*a[i]-5*fimin[i+1]);
	cout << res;
}