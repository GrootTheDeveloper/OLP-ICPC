#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val first
#define id second
ii a[100005];
struct node
{
	int l, r, k, id;
	bool operator<(const node &other) const
	{
		return k > other.k;
	}
}op[100005];
int ans[100005];
struct Segmentree
{
	vector <int> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
	}
	void update(int id, int l, int r, int pos)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l) return seg[id] = 1, void();
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos);
		update(id * 2 + 1, mid + 1, r, pos);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) >> 1;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	void add(int pos) { update(1, 1, n, pos);}
	int get(int l, int r) {return get(1, 1, n, l, r);}
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].val;
		a[i].id = i;
	}
	for (int i = 1; i <= q; i++)
		cin >> op[i].l >> op[i].r >> op[i].k, op[i].id = i;
	sort(a + 1, a + n + 1, greater<ii>());
	sort(op + 1, op + q + 1);
	Segmentree st(n);
	int l = 1;
	for (int i = 1; i <= q; i++)
	{
		while (a[l].val > op[i].k && l <= n) st.add(a[l++].id);
		ans[op[i].id] = st.get(op[i].l, op[i].r);
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

}