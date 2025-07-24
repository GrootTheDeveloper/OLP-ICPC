#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int dp[333][333];

void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++)
	for (int sum = n; sum >= 0; sum--)
	for (int cur = sum; cur >= 0; cur--)
		add(dp[i][sum], dp[i - 1][sum - cur]);
	cout << dp[k][n];
}