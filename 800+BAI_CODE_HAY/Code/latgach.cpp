#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int pre[500005], dp[500005];
int n, m;
void sub1()
{
	pre[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		dp[i] = pre[i - 1];
		pre[i] = (pre[i - 1] + dp[i]) % mode;
	}
	cout << dp[m];
}
void sub2()
{
	dp[1] = 2, dp[2] = 8;
	for (int i = 3; i <= m; i++)
		dp[i] = (6 * dp[i - 1] - 7 * dp[i - 2] + mode * mode) % mode;
	cout << dp[m];
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	if (n == 1) sub1();
	if (n == 2) sub2();
}