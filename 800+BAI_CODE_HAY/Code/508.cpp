#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], l[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	long long cur_min = 0, cur_sum = 0;
	l[0] = -1e9;
	for (int i = 1; i <= n; i++)
	{
		cur_sum += a[i];
		l[i] = max(l[i - 1], cur_sum - cur_min);
		cur_min = min(cur_min, cur_sum);
	}

	cur_min = 0, cur_sum = 0;
	long long ans = -1e9;
	for (int i = n; i >= 1; i--)
	{
		cur_sum += a[i];
		ans = max(ans, l[i - 1] + cur_sum - cur_min);
		cur_min = min(cur_min, cur_sum);
	}
	cout << ans;

}