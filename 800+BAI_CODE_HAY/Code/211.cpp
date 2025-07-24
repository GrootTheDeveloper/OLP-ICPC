#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Segmentree
{
	vector<vector<int>> seg;
	vector <int> lazy;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, vector<int> (3, 0));
		lazy.assign(n * 4 + 5, 0);
	}
	void add(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l) return seg[id][val] = 1, void();
		int mid = (l + r) >> 1;
		add(id << 1, l, mid, pos, val);
		add(id << 1 | 1, mid + 1, r, pos, val);
		for (int i = 0; i < 3; i++)
			seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
	}
	void push(int id)
	{
		if (lazy[id])
		{
			for (int i = 1; i <= lazy[id]; i++)
			{
				swap(seg[id << 1][0], seg[id << 1][1]);
				swap(seg[id << 1][0], seg[id << 1][2]);
				swap(seg[id << 1 | 1][0], seg[id << 1 | 1][1]);
				swap(seg[id << 1 | 1][0], seg[id << 1 | 1][2]);
			}
			lazy[id << 1] += lazy[id];
			lazy[id << 1 | 1] += lazy[id];
			lazy[id] = 0;
		}

	}
	void update(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return;
		if (u <= l && r <= v)
		{
			swap(seg[id][0], seg[id][1]);
			swap(seg[id][0], seg[id][2]);
			lazy[id] = (lazy[id] + 1) % 3;
			return;	
		}
		push(id);
		int mid = (l + r) >> 1;
		update(id << 1, l, mid, u, v);
		update(id << 1 | 1, mid + 1, r, u, v);
		for (int i = 0; i < 3; i++)
			seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id][0];
		int mid = (l + r) >> 1;
		push(id);
		return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
	}
	void add(int pos, int val) {add(1, 1, n, pos, val);}
	void Up(int l, int r) {update(1, 1, n, l, r);}
	int get(int l, int r) {return get(1, 1, n, l, r);}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	Segmentree st(n);
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		ai %= 3;
		st.add(i, ai);
	}
	while (q--)
	{
		int kind, u, v; cin >> kind >> u >> v;
		if (kind == 1) st.Up(u,v);
		else cout << st.get(u,v) << '\n';
	}
}