#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[5][10004], dp[10004][20];
bool check(int bit)
{
	for (int i = 1; i <= 3; i++)
		if ((bit >> i & 1) && (bit >> (i - 1) & 1)) return true;
	return false;
}
bool comon(int bit1, int bit2)
{
	return (bit1&bit2);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	int ans = -1e12;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j], ans = max(ans,a[i][j]);
    if (ans < 0) return cout << ans, 0;

	for (int pos = 1; pos <= n; pos++)
	{
		for (int cur = 0; cur <= 15; cur++)
		{
			if (check(cur)) continue;
			int cur_sum = 0;
			for (int i = 0; i <= 3; i++)
				if (cur >> i & 1) cur_sum += a[i + 1][pos];
			dp[pos][cur] = cur_sum;
			for (int last = 0; last <= 15; last++)
				if (!comon(last, cur) && !check(last)) dp[pos][cur] = max(dp[pos][cur], dp[pos - 1][last] + cur_sum);
			//dp[pos][cur] = max(dp[pos][cur], mx + cur_sum);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 15; j++)
			if (!check(j)) ans = max(ans, dp[i][j]);
    cout << ans;

}
