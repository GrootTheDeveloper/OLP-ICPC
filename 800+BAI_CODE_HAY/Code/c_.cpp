#include <bits/stdc++.h>
using namespace std;

int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = m - 2 * a[i];
		int pos = upper_bound(a + 1, a + n + 1, cur) - a - 1;
		ans += pos;
	}
	cout << ans;
}