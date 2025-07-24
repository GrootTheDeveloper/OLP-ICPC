#include <bits/stdc++.h>
using namespace std;


signed main()
{
	int m, n; cin >> m >> n;
	long long ans = 1ll * (m + n - 2) + 1ll *2 * (min(m, n) - 1);
	if (n % 2 == 0 && m == n) ans--;
	cout << ans;
}