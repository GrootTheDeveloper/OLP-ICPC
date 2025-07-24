#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;
int n, q;
int a[N], b[N], x[N], y[N], k[N];
int seg[N * 4], lazy[N * 4];

void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
}
void down(int id, int l, int r){
	if (lazy[id]){
		seg[id * 2] = seg[id * 2 + 1] = lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
		lazy[id] = 0;
	}
}
int get(int id, int l, int r, int pos){
	if (pos > r || pos < l)
		return 0;
	if (l == pos && l == r)
		return seg[id];
	down(id, l, r);
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, pos), get(id * 2 + 1, mid + 1, r, pos));
}
void update(int id, int l, int r, int u, int v, int val){
	if (u > r || v < l)
		return;
	if (u <= l && r <= v){
		seg[id] = val;
		lazy[id] = val;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void solve(){
	for (int i = 1; i <= q; i++){
		int type; cin >> type;
		if (type == 1){
			cin >> x[i] >> y[i] >> k[i];
			update(1, 1, n, y[i], y[i] + k[i] - 1, i);
		} else{
			int pos; cin >> pos;
			int id = get(1, 1, n, pos);
			if (id == 0)
				cout << b[pos] << '\n';
			else{
				//cout << id << ' ';
				cout << a[x[id] + (pos - y[id])] << '\n';
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}