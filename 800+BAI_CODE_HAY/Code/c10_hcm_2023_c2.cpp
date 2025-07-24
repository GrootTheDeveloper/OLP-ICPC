#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

ii a[300005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		int u, v; cin >> u >> v;
		if (v < u)
			a[++len] = make_pair(v, u);
	}
	sort(a + 1, a + len + 1);
	long long ans = m;
	int x = 0, y = 0;
	for (int i = 1; i <= len; i++)
	{
		if (a[i].fi <= y) y = max(y, a[i].se);
		else
		{
			ans += (y - x) * 2;
			x = a[i].fi;
			y = a[i].se;
		}
	}
	ans += (y - x) * 2;
	cout << ans;
}