#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[5555], l[6], r[6];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("golf.inp","r",stdin);
	freopen("golf.out","w",stdout);
	int n, d; cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	fill(dp + 1, dp + 5 * d + 1, inf);
	for (int i = 1; i <= 5 * d; i++)
	{
		for (int id = 1; id <= n; id++)
		for (int j = l[id]; j <= r[id]; j++)
		if (j <= i) dp[i] = min(dp[i], dp[i - j] + 1);
	}		
	int ans = inf;
	for (int i = 0; i <= 5 * d; i++)
		for (int j = i; j <= 5 * d; j++)
		{
			if (i + j >= d && d + j >= i && d + i >= j)
				ans = min(ans, dp[i] + dp[j]);
		}
	cout << (ans == inf? -1 : ans);
}