#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int mode = 1e9 + 7;
string s;
int n;
void input(){
	cin >> s;
	n = s.size();
	s = " " + s;
}
void solve(){
	int sum = 0,cnt = 0;
	for (int i = 1; i <= n; i++){
		sum = (sum + (1ll * sum * 10 % mode + 1ll * (cnt + 1) * (s[i] - '0') % mode) % mode) % mode;
		cnt = (1ll * cnt * 2 + 1) % mode;
	}
	cout << sum;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}