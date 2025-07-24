#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
bool check(int value)
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += a[i] / value + (a[i] % value != 0);
	return (cnt <= n);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];

	int l = 1, r = 1e9, ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) 
			ans = mid, r = mid - 1;
		else 
			l = mid + 1;
	}
	cout << ans;
}