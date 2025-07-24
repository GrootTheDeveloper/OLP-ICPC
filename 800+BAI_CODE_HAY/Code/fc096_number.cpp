#include <bits/stdc++.h>
using namespace std;

int cnt[111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		cnt[ai % k]++;
	}

	int ans = 0;
	for (int i = 1; i <= k / 2; i++)
	{
		if (i != k - i)
			ans += max(cnt[i], cnt[k - i]);
		else
			ans += (cnt[i] != 0);
	}
	ans += (cnt[0] != 0);
	cout << ans;
}