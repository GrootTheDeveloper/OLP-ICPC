#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], pre[100005];
double b[100005];
int n, k;
bool check(double x)
{
	int id = 0;
	double cur_min = 1e15;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + (a[i] - x);
		while (pre[i] - pre[id] >= k) cur_min = min(cur_min, b[id++]);
		if (b[i] - cur_min >= 0) return true;
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];


	double ans, l = 0, r = 1e15;
	while (r - l >= 0.00001)
	{
		double mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(4) << ans;
}