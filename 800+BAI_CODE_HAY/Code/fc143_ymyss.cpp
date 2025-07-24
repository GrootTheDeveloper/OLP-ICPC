#include <bits/stdc++.h>
using namespace std;

int a[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int pos;
	for (int i = 1; i <= n; i++) cin >> a[i], pos = (a[i] == 1? i : pos);
	int ans = INT_MAX;
	for (int i = pos - 1; i >= max(0, pos - k); i--)
	{
		int rig = n - (pos + (k - pos + i));
		ans = min(ans, i / (k - 1) + rig / (k - 1) + (i % (k - 1) != 0) + (rig % (k - 1) != 0));
	}
	cout << ans + 1;
}