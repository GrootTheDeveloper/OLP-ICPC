#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;
int n, a[N], lef[N], rig[N];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void init(){
	for (int i = 1; i <= n; i++){
		int pos = i - 1;
		while (a[pos] >= a[i])
			pos = lef[pos];
		lef[i] = pos;
	}
	for (int i = n; i >= 1; i--){
		int pos = i + 1;
		while (a[pos] >= a[i])
			pos = rig[pos];
		rig[i] = pos;
	}
}
void solve(){
	init();
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		int l = lef[i], r = rig[i] - 1;
		ans = max(ans, 1ll * a[i] * (r - l));
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}