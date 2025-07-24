#include <bits/stdc++.h>
using namespace std;
int cnt[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int num = 0, lim = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		num += (++cnt[ai] == 1);
		lim = max(lim, cnt[ai]);
	}

	cout << (lim == num? lim - 1 : min(lim, num));
}