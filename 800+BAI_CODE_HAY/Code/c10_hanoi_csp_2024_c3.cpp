#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[1000006], pre[1000006];
int m, n;

bool check(int x)
{
	for (int i = 0; i <= n - x; i++)
		if (pre[i + x] - pre[i] < m) return false;
	return true;
}	
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

	int ans, l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}