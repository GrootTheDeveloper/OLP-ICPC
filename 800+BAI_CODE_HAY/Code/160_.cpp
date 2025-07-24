#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long dp[N][3];
int a[N], b[N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	dp[1][1] = a[1]; dp[1][2] = b[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 1][2] + a[i], dp[i - 2][2] + a[i - 1] + a[i]);
		dp[i][2] = max(dp[i - 1][1] + b[i], dp[i - 2][1] + b[i - 1] + b[i]);
	}
	cout << max(dp[n][1], dp[n][2]);
}