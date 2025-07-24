#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second 

long long b[1000006];
ii a[1000006];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int limit = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		b[i] = a[i].fi + a[i].se;
		limit = max(limit, a[i].se);
	}

	sort(b + 1, b + n + 1, greater<int>());

	long long ans = 0;
	for (int i = 1; i <= min(n, q); i++)
	{
		b[i] += b[i - 1];
		ans = max(ans, b[i] + 1ll * limit * (q - i));
	}
	cout << ans;

}