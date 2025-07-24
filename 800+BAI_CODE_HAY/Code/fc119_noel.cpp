#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005], b[100005];
bool check(int x)
{
	int id = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= x) continue;
		while (b[id] + a[i] < x)
		{
			id++;
			if (id >= m + 1) return false;
		}
		id++;
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];

	int l = 1, r = 1e9;
	int ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
}