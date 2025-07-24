#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;

int dp[101][1001];	
void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, sum; cin >> n >> sum;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	for (int j = min(sum, i * 9); j >= 1; j--)
	{
		for (int k = 0; k <= 9; k++)
		if (j - k > 0) add(dp[i][j], dp[i - 1][j - k]);
	}
	cout << dp[n][sum];
}