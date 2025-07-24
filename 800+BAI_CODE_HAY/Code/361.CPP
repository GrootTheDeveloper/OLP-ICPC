#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
const int N = 2e5 + 5;
const int oo = 2e5 + 1;
int last[N], a[N], value[N], ans[N], seg[N * 4];
int n, q;
struct Data{
	int l, r, id;
	Data(): l(0), r(0), id(0){};
	Data(int a, int b, int c): l(a), r(b), id(c){};
	bool operator < (const Data &other)const{
		return r < other.r;
	}
}query[N];
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= q; i++)
		cin >> query[i].l >> query[i].r, query[i].id = i;
	sort(query + 1, query + q + 1);
}
void Update(int id, int l, int r, int pos){
	if (pos > r || pos < l)
		return;
	if (l == r && pos == l)
		return seg[id] = pos, void();
	int mid = (l + r) >> 1;
	Update(id * 2, l, mid, pos);
	Update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = (value[seg[id * 2]] < value[seg[id * 2 + 1]]? seg[id * 2] : seg[id * 2 + 1]);
}
int Get(int id, int l, int r, int u, int v){
	if (u > r || v < l)
		return oo;
	if (u <= l && r <= v)
		return seg[id];

	int mid = (l + r) >> 1;
	int t1 = Get(id * 2, l, mid, u, v), t2 = Get(id * 2 + 1, mid + 1, r, u, v);
	return (value[t1] < value[t2]? t1 : t2);
}
void update(int pos){
	Update(1, 1, n, pos);
}
int get(int l, int r){
	return Get(1, 1, n, l, r);
}
void solve(){
	int id = 1;
	value[oo] = 1e6;
	for (int i = 1; i <= q; i++){
		while (id <= query[i].r){
			value[last[a[id]]] = N;
			value[id] = last[a[id]];

			update(last[a[id]]);
			update(id);
			last[a[id]] = id;
			id++;
		}
		int tmp = get(query[i].l, query[i].r);
		if (value[tmp] < query[i].l)
			ans[query[i].id] = a[tmp];
		else
			ans[query[i].id] = 0;
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}