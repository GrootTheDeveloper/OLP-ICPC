#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		if (ai <= k) ans++;
		k -= ai;
	}
	cout << ans;
}