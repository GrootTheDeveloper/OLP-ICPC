#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[303][303];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	string s1, s2; cin >> s1 >> s2;
	s1 = " " + s1 + " ";
	s2 = " " + s2 + " ";

	for (int i = 0; i <= m; i++)
		fill(dp[i], dp[i] + n + 1, inf);

	for (int i = 1; i <= n; i++)
	if (s2[1] == s1[i]) dp[1][i] = 0;
	
	for (int pos = 2; pos <= m; pos++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (s1[i - 1] == s2[pos - 1] && s1[i] == s2[pos]) 
				dp[pos][i] = min(dp[pos][i], dp[pos - 1][i - 1] + 1);
			if (s1[i + 1] == s2[pos - 1] && s1[i] == s2[pos]) 
				dp[pos][i] = min(dp[pos][i], dp[pos - 1][i + 1] + 1);
		}

		for (int i = 1; i <= n; i++)
		if (s1[i] == s2[pos])
		{
			for (int j = 1; j <= n; j++)
			if (s1[i] == s1[j]) dp[pos][i] = min(dp[pos][i], dp[pos][j] + abs(i - j));
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[m][i]);
	cout << (ans == inf? -1 : ans);

}