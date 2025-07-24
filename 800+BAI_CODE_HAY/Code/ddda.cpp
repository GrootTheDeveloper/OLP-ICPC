#include <bits/stdc++.h>
using namespace std;


int dp[1000006];


signed main()
{
	int n; cin >> n;
	dp[1] = 2;
	dp[0] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] * 2 + dp[i - 2] * 3;
	cout << dp[n];
}