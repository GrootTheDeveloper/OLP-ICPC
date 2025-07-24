#include <bits/stdc++.h>
using namespace std;
const int mode = 123456789;
long long dp[1000006];
int n, a[1000006];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	long long sum = 1;
	for (int i = 1; i <= n; i++){
		sum = (sum - dp[a[i]] + mode) % mode;
		dp[a[i]] = (dp[a[i]] + sum) % mode;
		sum = (sum + dp[a[i]]) % mode;
	}
	int ans = 0;
	for (int i = 1; i <= 1e6; i++)
		ans = (ans + dp[i]) % mode;
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}