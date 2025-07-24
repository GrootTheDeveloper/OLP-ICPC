#include <bits/stdc++.h>
using namespace std;
long long a[200005], S, T;
int n, q;
void input(){
	cin >> n >> q >> S >> T;
	for (int i = 0; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		a[i] -= a[i + 1];
}
long long calc(long long &val){
	return (val < 0? S * val : T * val);
}
void solve(){
	long long result = 0;
	for (int i = 0; i < n; i++)
		result += calc(a[i]);
	while (q--){
		int l, r, x; cin >> l >> r >> x;
		long long last = calc(a[l - 1]) + (r < n? calc(a[r]) : 0);
		a[l - 1] -= x, a[r] += x;
		long long newval = calc(a[l - 1]) + (r < n? calc(a[r]) : 0);
		result += newval - last;
		cout << result << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}