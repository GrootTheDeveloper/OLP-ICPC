#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int l = 1, r = 2e9, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (mid - mid / n >= k)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans;
}