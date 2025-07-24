#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[3003][3003], n, m, s;

bool check(int x)
{
	for (int i = x; i <= m; i++)
		for (int j = x; j <= n; j++)
		{
			if (a[i][j] - a[i - x][j] - a[i][j - x] + a[i - x][j - x] <= s) 
				return true;
		}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n >> s;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	int l = 1, r = min(m, n);
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	while (check(l + 1) && l < n) l++;
	while (!check(l) && l > 0) l--;
	cout << l * l;
}