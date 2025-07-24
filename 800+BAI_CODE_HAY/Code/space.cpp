#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k, r, a[1000006], pre[1000006];


bool sub1()
{
	if (k != 1) return false;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos1 = lower_bound(a + 1, a + i + 1, a[i] - r) - a;
		int pos2 = upper_bound(a + i, a + n + 1, a[i] + r) - a - 1;
		res = max(res, pre[pos2] - pre[pos1 - 1]);
	}
	cout << res;
	return true;
}
int last[1000006];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		int po1 = lower_bound(a + 1, a + i + 1, a[i] - r) - a;
		int po2 = lower_bound(a + 1, a + po1 + 1, a[po1] - r) - a;
		last[i] = po2;
	}
}

bool sub2()
{
	if (k > 50) return false;
	init();
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = i;
		for (int j = 1; j <= k && pos > 0; j++)
			pos = last[pos] - 1;
		res = max(res, pre[i] - pre[pos]);
	}
	cout << res;
	return true;
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> r;
	a[1] = 1;
	for (int i = 2; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	for (int i = 1, ai; i <= n; i++) cin >> ai, pre[i] = pre[i - 1] + ai;
	if (sub1()) return 0;
	if (sub2()) return 0;


}