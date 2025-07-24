#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int seg[N * 4], h[N];
long long d[N];
int n;
void init(int id, int l, int r){
	if (l == r) return seg[id] = l, void();
	int mid = (l + r) >> 1;
	init(id * 2, l, mid);
	init(id * 2 + 1, mid + 1, r);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v){
	if (u > r || v < l)
		return 0;
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void update(int id, int l, int r, const int &pos, const int &val){
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 2; i <= n; i++)
		cin >> d[i], d[i] += d[i - 1];
}
void solve(){
	init(1, 1, n);
	for (int i = n; i >= 1; i--){
		int pos = upper_bound(d + i, d + n + 1, d[i] + h[i]) - d - 1;
		int new_pos = get(1, 1, n, i, pos);
		update(1, 1, n, i, new_pos);
	}
	int q; cin >> q;
	while (q--){
		int pos; cin >> pos;
		cout << get(1, 1, n, pos, pos) << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();		
}
//Huỳnh Tấn Đức 