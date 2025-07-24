#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 2e5 + 5;
long long a[200005], seg[2][N * 4], lazy[N * 4];
int n, q;
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = 1e15;
}
void down(int id, int l, int r){
	if (lazy[id]){
		int mid = (l + r) >> 1;
		long long &tmp = lazy[id];
		seg[0][id * 2] += 1ll * tmp * (mid - l + 1);
		seg[0][id * 2 + 1] += 1ll * tmp * (r - mid);
		lazy[id * 2] += tmp;
		lazy[id * 2 + 1] += tmp;
		tmp = 0;
	}
}
long long get(int id, int l, int r, int pos){
	if (pos == 0 || pos == n + 1)
		return 1e15;
	if (l == r && pos == l)
		return seg[0][id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	if (pos <= mid)
		return get(id * 2, l, mid, pos);
	else
		return get(id * 2 + 1, mid + 1, r, pos);
}
void Add(int id, int l, int r, int u, int v, const int &val){
	if (u > r || v < l)
		return;
	if (u <= l && r <= v){
		seg[0][id] += 1ll * (r - l + 1) * val;
		lazy[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	down(id, l, r);
	Add(id * 2, l, mid, u, v, val);
	Add(id * 2 + 1, mid + 1, r, u, v, val);
	seg[0][id] = seg[0][id * 2] + seg[0][id * 2 + 1];
}
void update_node(int id, int l, int r, int pos, const int &val){
	if (pos > r || pos < l)
		return;
	if (l == r && pos == l)
		return seg[1][id] = val, void();
	int mid = (l + r) >> 1;
	update_node(id * 2, l, mid, pos, val);
	update_node(id * 2 + 1, mid + 1, r, pos, val);
	seg[1][id] = seg[1][id * 2] + seg[1][id * 2 + 1];
}
long long value(int pos){
	return get(1, 1, n, pos);
}
void update_add(int l, int r, int x){
	Add(1, 1, n, l, r, x);
}
void update(int pos, int val){
	update_node(1, 1, n, pos, val);
}
void solve(){
	for (int i = 1; i <= n; i++)
		update(i, (a[i] > a[i + 1]?  1 : 0)), update_add(i, i, a[i]);
	while (q--){
		int l, r, x; cin >> l >> r >> x;
		update_add(l, r, x);
		update(l - 1, (value(l - 1) > value(l)));
		update(r, (value(r) > value(r + 1)));
		cout << seg[1][1] << '\n';
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}