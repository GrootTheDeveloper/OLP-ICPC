#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005], dp[200005][101];
vector<int> b;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b.push_back(a[i]), pre[i] = pre[i - 1] + a[i];

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	a[0] = 1e9 + 1;
	int idx = 0, tranf = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		if (a[i] - a[i - 1] != 1)
		{
			idx = i;
			tranf = pos;
		}
		for (int step = 1; step <= k; step++)
			ans = max(ans, dp[pos][step] = max(dp[pos][step], dp[tranf - 1][step - 1] + (pre[i] - pre[idx - 1])));
	}
	cout << ans;
	cout << '\n' << clock() / (double)1000 << " ms";

}