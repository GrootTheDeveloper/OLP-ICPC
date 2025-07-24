#include <bits/stdc++.h>
using namespace std;

int a[100005], b[4];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 1; i < n; i++)
		ans = max(ans, min(a[i], a[i + 1]));

	for (int i = 1; i < n - 1; i++)
	{
		b[1] = a[i], b[2] = a[i + 1], b[3] = a[i + 2];
		sort(b + 1, b + 4);
		ans = max(ans, b[2]);
	}
	cout << ans;
}