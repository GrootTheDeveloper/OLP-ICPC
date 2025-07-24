#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005], b[100005], n, l;

bool check(int mid)
{
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mid <= a[i]) continue;
		int dev = mid - a[i];
		cur += (dev / b[i] + (dev % b[i] != 0));
		if (cur > l) return 0;
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	int l = 1, r = 1e15;
	int ans = 0ll; 
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
}