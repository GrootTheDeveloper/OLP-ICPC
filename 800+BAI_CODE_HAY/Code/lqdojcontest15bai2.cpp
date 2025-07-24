#include <bits/stdc++.h>
using namespace std;

int a[5005][5005];
int n, k;
bool check(int x)
{
	for (int i = x; i <= n; i++)
	for (int j = x; j <= n; j++)
		if (a[i][j] - a[i - x][j] - a[i][j - x] + a[i - x][j - x] < k) return false;
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}
	int ans = -1, l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}