#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long bit1[N], bit2[N], a[N];
int n, q;

int get(int l, int r){
	int ans = 0;
	for (l = l - 1; l; l -= l & -l)
		ans -= bit2[l];
	for (; r; r -= r & -r)
		ans += bit2[r];
	return ans;
}
void update(int idx, int val){
	if (idx == 0)
		return;
	val = val - get(idx, idx);
	for (; idx <= n; idx += idx & -idx)
		bit2[idx] += val;
}
void add(int idx, int val){
	for (; idx <= n; idx += idx & -idx)
		bit1[idx] += val;
}
long long value(int idx){
	if (idx == 0 || idx == n + 1)
		return 1e15;
	long long ans = 0;
	for (int id = idx; id; id -= id & -id)
		ans += bit1[id];
	return a[idx] + ans;
}
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	for (int i = 1; i < n; i++)
		update(i, (a[i] > a[i + 1]));
	while (q--){
		int l, r, x; cin >> l >> r >> x;
		add(l, x);
		add(r + 1, -x);
		update(l - 1, (value(l - 1) > value(l)));
		update(r, (value(r) > value(r + 1)));
		cout << get(1, n) << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}