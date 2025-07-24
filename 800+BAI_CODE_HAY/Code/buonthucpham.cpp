#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second

ii a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, E, n; cin >> k >> E >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, f, c; cin >> x >> f >> c;
		a[i] = make_pair(E - x + c, f);
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (k >= a[i].se)
			ans += (a[i].se * a[i].fi), k -= a[i].se;
		else 
			ans += k * a[i].fi, k = 0;
	}
	cout << ans;
}