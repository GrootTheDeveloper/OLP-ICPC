#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[20];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l, r, x; cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	int MASK = (1 << n);
	int ans = 0;
	for (int mask = 0; mask < MASK; mask++)
	{
		int sum = 0, mi = 1e6, ma = 0;
		for (int i = 0; i < n; i++) 
			if ((mask >> i) & 1)
			{
				sum += a[i];
				ma = max(ma, a[i]);
				mi = min(mi, a[i]);
			} 
		if (l <= sum && sum <= r && ma - mi >= x) ans++;
	}
	cout << ans;
}