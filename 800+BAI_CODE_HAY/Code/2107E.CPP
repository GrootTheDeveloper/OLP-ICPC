#include <bits/stdc++.h>
using namespace std;

int a[100005], lef[100005], rig[100005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		lef[i] = 1;
		if (a[i] > a[i - 1])
			lef[i] += lef[i - 1];
		ans = max(ans, lef[i]);
	}

	for (int i = n; i >= 1; i--)
	{
		rig[i] = 1;
		if (a[i] < a[i + 1])
			rig[i] += rig[i + 1];
		ans = max(ans, rig[i]);
	}
	
	a[0] = -1;
	a[n + 1] = 1e9;
	for (int i = 1; i <= n; i++)
	{
		if (a[i + 1] - a[i - 1] >= 2)
			ans = max(ans, lef[i - 1] + rig[i + 1] + 1);
		ans = max(ans, lef[i - 1] + 1);
		ans = max(ans, rig[i + 1] + 1);
	}
	cout << ans;
}