#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int dp[1003][1003][7];
signed main()
{
	int a, b; cin >> a >> b;
	if (a * b > 1e6) return 0;
	dp[0][0][1] = 1;

	for (int i = 1; i <= a; i++)
	{
		dp[i][0][1] = dp[i - 1][0][6];
		dp[i][0][6] = dp[i - 1][0][1];
	}
	for (int i = 1; i <= b; i++)
	{
		dp[0][i][1] = dp[0][i - 1][2];
		dp[0][i][2] = dp[0][i - 1][1];
	}
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
		{
			dp[i][j][1] = (dp[i - 1][j][6] + dp[i][j - 1][2]) % mode;
			dp[i][j][2] = (dp[i - 1][j][3] + dp[i][j - 1][1]) % mode;
			dp[i][j][3] = (dp[i][j - 1][4] + dp[i - 1][j][2]) % mode;
			dp[i][j][4] = (dp[i - 1][j][5] + dp[i][j - 1][3]) % mode;
			dp[i][j][5] = (dp[i][j - 1][6] + dp[i - 1][j][4]) % mode;
			dp[i][j][6] = (dp[i - 1][j][1] + dp[i][j - 1][5]) % mode;
		}
	cout << dp[a][b][1];
}