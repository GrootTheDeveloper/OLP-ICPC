#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int dp[10004][105], a[10004];
string K;
int D, n;
void add(int &a, int b){
	a += b;
	if (a >= mode)
		a -= mode;
}
int calc(int pos, bool lim, int sum){
	if (pos < 1)
		return sum == 0;
	if (dp[pos][sum] != -1 && !lim)
		return dp[pos][sum];
	int mx = (lim? a[pos] : 9);
	int res = 0;
	for (int x = 0; x <= mx; x++)
		add(res, calc(pos - 1, (lim && x == mx), (sum + x) % D));
	if (!lim)
		dp[pos][sum] = res;
	return res;
}

void input(){
	cin >> K >> D;
}
void solve(){
	while (!K.empty()){
		a[++n] = K.back() - '0';
		K.pop_back();
	}
	memset(dp, -1, sizeof(dp));
	cout << calc(n, true, 0) - 1;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}