#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

struct input
{
	int id, deadline, profit;
	bool operator < (input &other) const 
	{
		return deadline < other.deadline;
	}
};
ii dp[1005], tmp[1005];
input a[1005];
void solve()
{
	for (int i = 0; i <= 1000; i++)
		dp[i] = tmp[i] = make_pair(0, 0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].id >> a[i].deadline >> a[i].profit;
	sort(a + 1, a + n + 1);
	for (int x = 1; x <= n; x++)
	{
		for (int i = 1; i <= 1000; i++)
		{
			if (i <= a[x].deadline)dp[i] = max({dp[i - 1], dp[i], make_pair(tmp[i - 1].fi + a[x].profit, tmp[i - 1].se + 1)});
			else dp[i] = max(dp[i], dp[i - 1]);
		}
		
		for (int i = 1; i <= 1000; i++)
			tmp[i] = dp[i];
	}
	ii ans = make_pair(0, 0);
	for (int i = 1; i <= 1000; i++)
		ans = max(ans, dp[i]);
	cout << ans.se << ' ' << ans.fi << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}