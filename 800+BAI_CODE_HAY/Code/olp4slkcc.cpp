#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct dta{int fi,se;};
dta a[100005];
bool cmp(dta a, dta b)
{
	if (a.fi==b.fi) return a.se>b.se;
	return a.fi<b.fi;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s; cin >> n >> s;
	for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1,cmp);
	int res=0;
	for (int i=1;i<=n;i++) 
	if (s>=a[i].fi) res++,s+=a[i].se;
	cout << res;
}