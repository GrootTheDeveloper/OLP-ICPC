#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
long long pre[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int q; cin >> q;
	while (q--)
	{
		int l, r, x; cin >> l >> r >> x;
		cout << a[x] * (x - l + 1) - (pre[x] - pre[l - 1]) + (pre[r] - pre[x]) - a[x] * (r - x) << '\n';
	}
}