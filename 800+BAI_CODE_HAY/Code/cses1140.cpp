#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct dta{int fi,se,val;};
dta a[200005];
bool cmp(dta a, dta b)
{
	return a.se<b.se;
}
int f[200005],last[200005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se >> a[i].val;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) last[i]=a[i].se;
	for (int i=1;i<=n;i++)
	{
		int pos=lower_bound(last+1,last+i+1,a[i].fi)-last-1;
		f[i]=max(f[i-1],f[pos]+a[i].val);
	}
	cout << f[n];
}