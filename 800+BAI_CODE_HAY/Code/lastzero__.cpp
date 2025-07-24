#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k;
int v2[111], v5[111];
int dp[111][3050];

void sub1()
{
	int MASK = (1 << n) - 1;
	int ans = 0;
	for (int mask = 1; mask <= MASK; mask++)
	{
		if (__builtin_popcount(mask) != k) continue;
		int d2 = 0, d5 = 0;
		for (int i = 0; i < n; i++)
		if (mask >> i & 1) d2 += v2[i + 1], d5 += v5[i + 1];
		ans = max(ans, min(d2, d5));
	}
	cout << ans << ' ';
}

void sub2()
{
	int sum = 0;
	for (int pos = 1; pos <= n; pos++)
	{
		sum += v5[pos];
		for (int i = k; i >= 1; i--)
			for (int j = sum; j >= v5[i]; j--)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v5[pos]] + v2[pos]);
	}
	int ans = 0;
	for (int i = 1; i <= sum; i++)
		ans = max(ans, min(i, dp[k][i]));
	cout << ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		while (ai % 2 == 0) v2[i]++, ai /= 2;
		while (ai % 5 == 0) v5[i]++, ai /= 5;
	}
	sub1();
	sub2();
}