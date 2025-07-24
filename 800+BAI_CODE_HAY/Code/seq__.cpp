#include <bits/stdc++.h>
using namespace std;

long long a[100005], lef[100005], rig[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	lef[1] = a[1];
	for (int i = 2; i <= n; i++)
		lef[i] = max(lef[i - 1], a[i]);
	rig[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		rig[i] = max(rig[i + 1], a[i]);

	long long ans = 0;
	for (int i = 2; i < n; i++)
		ans = max(ans, lef[i - 1] + rig[i + 1] - a[i]);
	cout << ans;
}