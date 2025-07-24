#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m,n,a[500004];
bool check(int x)
{
	int pos=1;
	for (int i=2;i<=m;i++)
	{
		pos=lower_bound(a+pos+1,a+n+1,a[pos]+x)-a;
		if (pos==n+1) return false;
	}
	return true;
}

void solve()
{
	int l=1,r=(int)1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	while (check(l+1)) l++;
	while (!check(l)) l--;
	cout << l << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("ABSF.INP","r",stdin);
	freopen("ABSF.OUT","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i=1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		solve();
	}
}