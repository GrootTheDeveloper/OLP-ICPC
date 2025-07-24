#include <bits/stdc++.h>
using namespace std;
const int lim = 1e7 + 5;

int divs[lim], cnt[lim];
long long dp[lim];

int mask(int n)
{
	int ans = 1;
	while (n != 1)
	{
		int k = divs[n], d = 0;
		while (n % k == 0) n /= k, d++;
		if (d & 1) ans *= k;
	}
	return ans;
}
void init()
{
	for (int i = 2; i <= 1e7; i++)
	if (!divs[i]) for (int j = i; j <= 1e7; j += i) divs[j] = i;

	for (int i = 1; i <= 1e7; i++)
	{
		int cur = mask(i);
		dp[i] = dp[i - 1] + 1ll * cnt[cur] * (cnt[cur] - 1) / 2;
		cnt[cur]++;
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	int t; cin >> t;
	long long ans = 0;
	while (t--)
	{
		int n; cin >> n;
		ans = ans ^ dp[n];
	}
	cout << ans;
}