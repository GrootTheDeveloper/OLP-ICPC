#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct dta{int fi,se;};

dta a[100005];

bool cmp(dta a, dta b)
{
	return a.fi<b.fi;
}
void solve()
{
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se,a[i].se--;
	sort(a+1,a+n+1,cmp);
	int x;
	while (m--)
	{
		cin >> x;
		if (x>a[n].se) {cout << -1 << '\n';continue;}
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (a[mid].se<x) l=mid+1;else r=mid-1;
		}
		while (a[l].se<x) l++;
		while (a[l-1].se>=x) l--;
		if (a[l].fi<=x && x<=a[l].se) cout << 0;
		else cout << a[l].fi-x;
		cout << '\n';
	}
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}