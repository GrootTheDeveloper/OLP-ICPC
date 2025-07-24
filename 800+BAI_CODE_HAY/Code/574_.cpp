#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int dp[200005], pre[200005];
void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	int n, k; cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		if (i > k) add(dp[i], pre[i - k]);
		add(pre[i], dp[i] + pre[i - 1]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		add(ans, dp[i]);
	cout << ans + 1;

}