#include <bits/stdc++.h>
using namespace std;


bool palind[5005][5005];
int dp[5005][5005];
string s;
void input(){
	cin >> s;
}
void solve(){
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++){
		palind[i][i] = true;
		dp[i][i] = 1;
		if (i < n){
			dp[i][i + 1] = (s[i] == s[i + 1]? 3 : 2);
			palind[i][i + 1] = (s[i] == s[i + 1]);
		}
	}
	for (int len = 3; len <= n; len++){
		for (int i = 1; i + len - 1 <= n; i++){
			int j = i + len - 1;
			palind[i][j] = (palind[i + 1][j - 1] && s[i] == s[j]);
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + (palind[i][j]);
		}
	}
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		cout << dp[l][r] << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}