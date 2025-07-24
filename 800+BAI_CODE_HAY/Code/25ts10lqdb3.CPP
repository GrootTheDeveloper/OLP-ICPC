#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 6;
int n;
int a[N];
ii l[N], r[N];

void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
long long calc(ii x, ii y, int c){
	long long ans = -1e18;
	ans = max(ans, 1ll * (x.fi - c) * (c - y.fi));
	ans = max(ans, 1ll * (x.fi - c) * (c - y.se));
	ans = max(ans, 1ll * (x.se - c) * (c - y.fi));
	ans = max(ans, 1ll * (x.se - c) * (c - y.se));
	return ans;
}
void solve(){
	l[0] = {-1e7, 1e7};
	for (int i = 1; i <= n; i++){
		l[i].fi = max(l[i - 1].fi, a[i]);
		l[i].se = min(l[i - 1].se, a[i]);
	}
	r[n + 1] = {-1e7, 1e7};
	for (int i = n; i >= 1; i--){
		r[i].fi = max(r[i + 1].fi, a[i]);
		r[i].se = min(r[i + 1].se, a[i]);
	}
	long long ans = -1e18;
	for (int i = 2; i < n; i++){
		ans = max(ans, calc(l[i - 1], r[i + 1], a[i]));
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("NHIETDO.INP","r",stdin);
	freopen("NHIETDO.OUT","w",stdout);
	input();
	solve();
}