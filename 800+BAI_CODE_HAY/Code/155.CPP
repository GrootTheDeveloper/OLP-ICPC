#include <bits/stdc++.h>
using namespace std;
const int mode = 123456789;
int n, k;
int a[2222], dp[2222][2222], sum[2222];
int lim;
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], lim = max(lim, a[i]);
}
void solve(){
	sum[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = k; j >= 1; j--){
			sum[j] = (sum[j] - dp[a[i]][j] + mode) % mode;
			dp[a[i]][j] = sum[j - 1];
			sum[j] = (sum[j] + dp[a[i]][j]) % mode;
		}
	}
	cout << sum[k];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}