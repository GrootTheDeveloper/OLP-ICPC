#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1000005];
long long pre[1000006];

bool check(int value)
{
	int pos = lower_bound(a + 1, a + n + 1, value) - a - 1;
	return (pre[n] - pre[pos]) - 1ll * (n - pos) * value >= m;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];

	int l = 1, r = 1e9, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) 
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans;
}