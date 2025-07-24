#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k;
int a[100005];
int pre[100005];
bool check(int x)
{
	int pos = 0;
	for (int i = 1; i <= k; i++)
		pos = upper_bound(pre + pos + 1, pre + n + 1, pre[pos] + x) - pre - 1;
	return pos == n;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int l = 1, r = 1e15, ans; 
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}