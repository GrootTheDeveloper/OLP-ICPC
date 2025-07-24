#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
struct Segmentree
{
	vector <int> seg, lazy;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
		lazy.assign(n * 4 + 5, 0);
		build(1, 1, n);
	}
	void build(int id, int l, int r)
	{
		if (l == r) return seg[id] = a[l], void();
		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		seg[id] = min(seg[id * 2],seg[id * 2 + 1]);
	}
	void push(int id, int l, int r)
	{
		int mid = (l + r) >> 1;
		if (lazy[id])
		{
			seg[id * 2] += lazy[id];
			seg[id * 2 + 1] += lazy[id];
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
			lazy[id] = 0;
		}
	}
	void update(int id, int l, int r, int u, int v, int val)
	{
		if (u > r || v < l) return;
		if (u <= l && r <= v) 
		{
			seg[id] += val;
			lazy[id] += val;
			return;
		}
		push(id, l, r);
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, u, v, val);
		update(id *2 + 1, mid + 1, r, u, v, val);
		seg[id] = min(seg[id * 2],seg[id * 2 + 1]);
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return (int)1e9;
		if (u <= l && r <= v) return seg[id];
		push(id, l, r);
		int mid = (l + r) >> 1;
		return min(get(id * 2, l, mid, u, v),get(id * 2 + 1, mid + 1, r, u, v));
	}
	void Up(int u, int v, int val) { update(1, 1, n, u, v, val);}
	int sum(int u, int v) {return get(1, 1, n, u, v);}
};



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	Segmentree st(n);
	while (q--)
	{
		int kind, u, v, x;
		cin >> kind >> u >> v;
		if (kind == 1)
		{
			cin >> x;
			st.Up(u,v,x);
		} else cout << st.sum(u,v) << '\n';
	}
}