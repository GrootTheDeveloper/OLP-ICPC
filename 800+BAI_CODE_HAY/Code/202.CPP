#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Segmentree
{
	vector <int> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
	}
	void update(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l) return seg[id] += val, void();
		int mid = l + r >> 1;
		update(id * 2, l, mid, pos, val);
		update(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return (int)1e15;
		if (u <= l && r <= v) return seg[id];
		int mid = l + r >> 1;
		return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
	}
	void Up(int pos, int val)
	{
		update(1, 1, n, pos, val);
	}
	int get(int l, int r)
	{
		return get(1,1,n,l,r);
	}
};



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	Segmentree st(n);
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		st.Up(i, ai);
	}
	//for (int i = 1; i <= n; i++) cout << st.get(i,i) << ' ';
	while (m--)
	{
		int kind, u, v; cin >> kind >> u >> v;
		if (kind == 1) st.Up(u,v);
		else cout << st.get(u,v) << '\n';
	}
}