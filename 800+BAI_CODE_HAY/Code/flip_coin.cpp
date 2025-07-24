#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Segmentree
{
	vector <int> seg, lazy;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
		lazy.assign(n * 4 + 5, 0);
	}
	void down(int id, int l, int r)
	{
		int mid = (l + r) >> 1;
		if (lazy[id])
		{
			seg[id * 2] = (mid - l + 1) - seg[id * 2];
			seg[id * 2 + 1] = (r - mid) - seg[id * 2 + 1];
			lazy[id * 2] = (lazy[id * 2] + 1) % 2;
			lazy[id * 2 + 1] = (lazy[id * 2 + 1] + 1) % 2;
			lazy[id] = 0;
		}
	}
	void update(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return;
		if (u <= l && r <= v)
		{
			seg[id] = (r - l + 1) - seg[id];
			lazy[id] = (lazy[id] + 1) % 2;
			return;
		}
		down(id, l, r);
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, u, v);
		update(id * 2 + 1, mid + 1, r, u, v);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		down(id, l, r);
		int mid = (l + r) >> 1;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	int get(int l, int r)
	{
		return get(1, 1, n, l, r);
	}
	void Up(int l, int r)
	{
		update(1, 1, n, l, r);
	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("flipcoin.inp","r",stdin);
	freopen("flipcoin.out","w",stdout);
	int n, q; cin >> n >> q;
	Segmentree st(n);
	while (q--)
	{
		int kind, l, r; cin >> kind >> l >> r;
		if (kind == 0) st.Up(l, r);
		else cout << st.get(l, r) << '\n';
	}
}