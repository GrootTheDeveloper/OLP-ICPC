#include <bits/stdc++.h>
using namespace std;
int cnt[100], a[20], n;
long long dp[20], X;
void input(){
	cin >> X;
}
void init(){
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			cnt[i + j]++;
	while (X){
		a[++n] = X % 10;
		X /= 10;
	}
	reverse(a + 1, a + n + 1);
}
void solve(){
	init();
	dp[0] = 1;
	dp[1] = cnt[a[1]];
	for (int i = 2; i <= n; i++){
		dp[i] += dp[i - 1] * cnt[a[i]];
		if (a[i - 1] * 10 + a[i] > 9){
			dp[i] += dp[i - 2] * cnt[a[i - 1] * 10 + a[i]];
		}
	}
	cout << dp[n];
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}