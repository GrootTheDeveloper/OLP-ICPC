#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005], dp[4][100005];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];


	dp[1][0] = dp[2][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = -1e15;
	long long cur_min = 0;
	for (int i = 1; i <= n; i++){
		dp[1][i] = max(dp[1][i - 1], a[i] - cur_min);
		cur_min = min(cur_min, a[i]);
	}
	cur_min = 0;
	for (int i = 2; i <= n; i++){
		dp[2][i] = max(dp[2][i - 1], a[i] - cur_min);	
		cur_min = min(cur_min, a[i] - dp[1][i]);
	}
	cur_min = 0;
	for (int i = 3; i <= n; i++){
		dp[3][i] = max(dp[3][i - 1], a[i] - cur_min);
		cur_min = min(cur_min, a[i] - dp[2][i]);
	}
	cout << dp[3][n];
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}