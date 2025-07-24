#include <bits/stdc++.h>
using namespace std;
#define int long long 
//#define double long double
#define ii pair<double, int>
#define val first
#define idx second
int n, l, r;
double pre[1000006], a[1000006];

void sub1()
{
	double res = -1e15;
	for (int i = 1; i <= n; i++)
		for (int j = i + l - 1; j <= n; j++)
			if (j - i + 1 <= r) res = max(res, (pre[j] - pre[i - 1]) / (j - i + 1));
	cout << res;
}

bool check(double x)
{
	priority_queue <ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i] - x;
		if (i >= l) 
		{
			q.push({pre[i - l], i - l});
			while (r < i - q.top().idx) q.pop();
			if ((pre[i] - q.top().val) / (i - q.top().idx) >= 0) return true;
		}
	}
	return false;
}
double inc = 0.00001;
void sub2()
{
	double lef = -1e7, rig = 1e9;
	double ans;
	while (lef < rig)
	{
		double mid = (lef + rig) / 2;
		if (check(mid)) ans = mid, lef = mid + inc;
		else rig = mid - inc;
	}
	if (check(((int)ans * 100000 + 1) / 100000.0)) ans += inc;
	cout << fixed << setprecision(4) << ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], pre[i] = a[i] + pre[i - 1];
	// if (n <= 2000) sub1();
	// else sub2();
	sub2();
}