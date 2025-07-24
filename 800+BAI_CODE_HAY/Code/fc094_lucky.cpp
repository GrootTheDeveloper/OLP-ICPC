#include <bits/stdc++.h>
using namespace std;

int a[300005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	long long cur = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], cur += a[i];
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cur -= a[i];
		ans += 1ll * a[i] * cur;
	}
	cout << ans;
}