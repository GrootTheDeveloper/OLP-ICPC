#include <bits/stdc++.h>
using namespace std;

int dp[100004], p[111], c[111];
int n, x;
void input(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> c[i];
}
void solve(){
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = p[i]; j <= 2 * x; j++)
			dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
	int ans = 1e9;
	for (int i = x; i <= 2 * x; i++)
		ans = min(ans, dp[i]);
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}