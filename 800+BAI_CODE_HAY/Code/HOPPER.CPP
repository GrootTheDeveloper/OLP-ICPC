#include <bits/stdc++.h>
using namespace std;
#define int long long 
long long sqr(int x) {return 1ll * x * x;}
long long round_on(long long x)
{
	int ans, l = 1, r = 1e9;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (1ll * mid * mid >= x)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int u, v; cin >> u >> v;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	if (x2 < x1) swap(x2, x1);
	if (y2 < y1) swap(y2, y1);

	if (u >= x1 && u <= x2 && v >= y1 && v <= y2)
		return cout << 0, 0;
	if (u >= x1 && u <= x2)
		return cout << min(abs(v - y1), abs(v - y2)), 0;
	if (v >= y1 && v <= y2)
		return cout << min(abs(u - x1), abs(u - x2)), 0;

	long long ans = min({sqr(u - x1) + sqr(v - y1), sqr(u - x1) + sqr(v - y2), sqr(u - x2) + sqr(v - y1), sqr(u - x2) + sqr(v - y2)});
	cout << round_on(ans);
}