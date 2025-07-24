#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n;
int a[555];

namespace sub1
{

	void work()
	{
		int MASK = (1 << n) - 1;
		int ans = 0;
		for (int mask = 1; mask <= MASK; mask++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			if (mask >> i & 1)
				cur = cur * 10 + a[i + 1];
			ans += cur;
		}
		cout << ans << ' ';
	
	}

	int c[555][555], dp[555][555];

	void init(int n)
	{
		for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = (j == 0 || j == i ? 1 : c[i - 1][j - 1] + c[i - 1][j]);
	}

	void solve()
	{
		init(n);
		for (int i = 1; i <= n; i++)
			dp[i][1] = a[i];

		for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 1; j--)
		for (int k = 1; k <= j; k++)
		{
			int tag = dp[j][k] * 10 + c[j - 1][k - 1] * a[i];
			dp[i][k + 1] += tag;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			ans += dp[i][j];
		cout << ans;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for (char c : s)
		a[++n] = c - '0';

	sub1::work();
	sub1::solve();
}