#include <bits/stdc++.h>
using namespace std;
long long dp[20][11][11];
int a[20], n;
long long L, R;
long long calc(int pos, bool lim, int last1, int last2){
	if (pos < 1){
		return (last1 != 10);
	}
	if (!lim && dp[pos][last1][last2] != -1)
		return dp[pos][last1][last2];
	int mx = (!lim? 9 : a[pos]);
	long long ans = 0;
	for (int i = 0; i <= mx; i++){
		if (i == 0){
			if (last1 == 10)
				ans += calc(pos - 1, lim && (i == a[pos]), 10, 10);
			else{
				if (i != last1 && i != last2)
					ans += calc(pos - 1, lim && (i == a[pos]), 0, last1);
			}
		} else{
			if (i != last1 && i != last2)
				ans += calc(pos - 1, lim && (i == a[pos]), i, last1);
		}
	}
	if (!lim) dp[pos][last1][last2] = ans;
	return ans;
}


long long G(long long x){
	n = 0;
	while (x) a[++n] = x % 10, x /= 10;
	return calc(n, true, 10, 10);
}

void input(){
	cin >> L >> R;
}
void solve(){
	memset(dp, -1, sizeof(dp));
	cout << G(R) - G(L - 1);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}