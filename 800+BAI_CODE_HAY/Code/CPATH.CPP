#include <bits/stdc++.h>
using namespace std;
const int mode = 1e6 + 3;
int dp[1111][1111];
char a[1111][1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++)
		a[i][j] = ' ';
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	
	string s; cin >> s;
	s = " " + s;
	
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (s[i + j - 1] == a[i][j])
	{
		if (s[i + j - 2] == a[i - 1][j])
			dp[i][j] += dp[i - 1][j];
		if (s[i + j - 2] == a[i][j - 1])
			dp[i][j] += dp[i][j - 1];
		dp[i][j] %= mode;
	}	
	cout << dp[n][n];
}