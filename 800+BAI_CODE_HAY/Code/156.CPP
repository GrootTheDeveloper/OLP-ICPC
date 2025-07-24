#include <bits/stdc++.h>
using namespace std;

int dp[10004], W[10004], V[10004];
void solve(){
	int n, m; cin >> n >> m;
	int len = 0;
	while (n--){
		int w, v, a; cin >> w >> v >> a;
		int cut = 1;
		while (a >= cut){
			++len;
			W[len] = w * cut, V[len] = v * cut;
			a -= cut;
			cut = cut * 2;
		}
		if (a > 0){
			++len;
			W[len] = a * w;
			V[len] = a * v;
		}
	}
	for (int i = 1; i <= len; i++)
		for (int j = m; j >= W[i]; j--)
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
	for (int i = 1; i <= m; i++)
		dp[i] = max(dp[i], dp[i - 1]);
	cout << dp[m];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}