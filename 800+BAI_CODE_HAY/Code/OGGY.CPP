#include <bits/stdc++.h>
using namespace std;
int a[22];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	int MASK = (1 << n) - 1;
	for (int mask = 1; mask <= MASK; mask++)
	{
		long long mul = 1;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1) mul *= a[i + 1];
		ans += ((__builtin_popcount(mask) & 1)? m / mul : -m / mul);
	}
	cout << ans;
}