#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], pre[100005];
int n;
int Find(int u, int v)
{
	int ans = INT_MAX, pos = u;
	int l = u, r = v;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int sl = pre[mid] - pre[u - 1];
		int sr = pre[v] - pre[mid];
		if (abs(sl - sr) < ans) pos = mid, ans = abs(sl - sr);
		if (sl > sr) r = mid - 1;
		else l = mid + 1;
	}
	return pos;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int ans = INT_MAX;
	for (int y = 2; y <= n - 2; y++)
	{
		int x = Find(1, y);
		int z = Find(y + 1, n);
		int s1 = pre[x], s2 = pre[y] - pre[x];
		int s3 = pre[z] - pre[y], s4 = pre[n] - pre[z];
		ans = min(ans, max({s1,s2,s4,s3})-min({s1,s2,s3,s4}));
	}
	cout << ans;
}