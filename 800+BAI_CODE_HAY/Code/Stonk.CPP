#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, mode = 1e9 + 7;
long long seg[N * 4], sum[N * 4], lazy[N * 4];
int n, q;
void down(int id, int l, int r){
	if (lazy[id]){
		lazy[id * 2] = (lazy[id * 2] + lazy[id]) % mode;
		lazy[id * 2 + 1] =(lazy[id * 2 + 1] +  lazy[id]) % mode;
		sum[id * 2] = (sum[id * 2] + 1ll * seg[id * 2] * lazy[id] % mode) % mode;
		sum[id * 2 + 1] = (sum[id * 2 + 1] + 1ll * seg[id * 2 + 1] * lazy[id] % mode) % mode;
		lazy[id] = 0;
	}
}
void add(int id, int l, int r, int pos, int val){	
	if (pos > r || pos < l)
		return;
	if (pos == l && l == r)
		return seg[id] = (seg[id] + val + mode) % mode, void();
	down(id, l, r);
	int mid = (l + r) >> 1;
	add(id * 2, l, mid, pos, val);
	add(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % mode;
}
int rut(int id, int l, int r, int pos){
	if (pos > r || pos < l)
		return 0;
	if (pos == l && r == l){
		int tmp = sum[id];
		sum[id] = 0;
		return tmp;
	}
	int mid = (l + r) >> 1;
	down(id, l, r);
	int t1 = rut(id * 2, l, mid, pos);
	int t2 = rut(id * 2 + 1, mid + 1, r, pos);
	sum[id] = (sum[id * 2] + sum[id * 2 + 1]) % mode;
	return (t1 + t2) % mode;
}
void vohan(){
	int money = 0, cophiu = 0;
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int pos, delta; cin >> pos >> delta;
			cophiu = (cophiu + delta) % mode;
		}
		if (type == 2){
			int v; cin >> v;
			money = (money + cophiu * v) % mode;
		}
		if (type == 3){
			int pos; cin >> pos;
			cout << money << '\n';
			money = 0;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	if (n == 1){
		vohan();
		return 0;
	}
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int pos, delta; cin >> pos >> delta;
			add(1, 1, n, pos, delta);
		}
		if (type == 2){
			int v; cin >> v;
			lazy[1] = (lazy[1] + v) % mode;
		}
		if (type == 3){
			int pos; cin >> pos;
			cout << rut(1, 1, n, pos) << '\n';
		}

	}
}