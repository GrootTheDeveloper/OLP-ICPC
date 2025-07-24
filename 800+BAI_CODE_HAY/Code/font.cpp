#include <bits/stdc++.h>
using namespace std;
int n;
int Mask[30];
int ans = 0;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		for (char &c : s)
			Mask[i] |= (1 << (c - 'a'));
	}
}

void Try(int i, int MASK){
	if (i > n)
		return ans += (__builtin_popcount(MASK) == 26), void();
	Try(i + 1, MASK);
	Try(i + 1, MASK | Mask[i]);
}
void solve(){
	Try(1, 0);
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}