#include <bits/stdc++.h>
using namespace std;
unordered_map<int, long long> dp;
long long calc(int n){
	if (dp.find(n) != dp.end())
		return dp[n];
	if (n / 2  + n / 3 + n / 4 < n)
		return dp[n] = n;
	return dp[n] = calc(n / 2) + calc(n / 3) + calc(n / 4);
}
void solve(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		cout << calc(n) << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}