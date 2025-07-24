#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 0, neg = 0, act = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		if (ai > 0)
			ans = max(ans, ++act), neg = 0;
		if (ai < 0)
			ans = max(ans, ++neg), act = 0;
		if (ai == 0)
			neg = 0, act = 0;
	}
	cout << ans;
}