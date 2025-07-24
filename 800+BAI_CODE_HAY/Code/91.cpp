#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, a[100005], k;
bool check(double x)
{
	long long count_slice = 0;
	for (int i = 1; i <= n; i++)
	{
		double cur_slice = a[i] / x;
		count_slice += trunc(cur_slice);
	}
	return count_slice >= k;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], a[i] = a[i] * a[i];

	double l = 0, r = 1e10;
	while (r - l >= 0.000001)
	{
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(6) << l;
}