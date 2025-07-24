#include <bits/stdc++.h>
using namespace std;

long long a[100005], pre[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i] * i;
		a[i] += a[i - 1];
	}

	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << (pre[r] - pre[l - 1]) - (a[r] - a[l - 1]) * (l - 1) << '\n';
	}
}