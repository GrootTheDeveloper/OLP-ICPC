#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005];
double b[100005];

bool check(double x)
{
	double cur_min = 0;
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + (a[i] - x);
		if (i >= k)
		{
			cur_min = min(cur_min, b[i - k]);
			if (cur_min <= b[i]) return true;
		}
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	double l = 0, r = 1e10;
	while (r - l >= 0.00001)
	{
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}	
	cout << fixed << setprecision(4) << l;
}