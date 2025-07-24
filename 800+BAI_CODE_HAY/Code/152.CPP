#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
string s;
int n, dp[1111][1111];
void add(int &a, int b){
	a += b;
	if (a >= mode)
		a -= mode;
}
void input(){
	cin >> s;
	n = s.size();
	s = " " + s;
}
void solve(){
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int delta = 0; delta <= min(i, n - i); delta++){
			if (s[i] == '(' || s[i] == '?')
				add(dp[i][delta], (delta != 0? dp[i - 1][delta - 1] : 0));
			if (s[i] == ')' || s[i] == '?')
				add(dp[i][delta], dp[i - 1][delta + 1]);
		}
	}
	cout << dp[n][0];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}