#include <bits/stdc++.h>
using namespace std;

int last_id[100005], a[100005];
struct node
{
	int x, y, id;
	bool operator<(const node &other) const
	{
		return (y == other.y? x < other.x : y < other.y);
	}
}op[100005];
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
		if (l == r && pos == l) return seg[id] = 1 - seg[id], void();
		int mid = l + r >> 1;
		update(id * 2, l, mid, pos);
		update(id * 2 + 1, mid + 1, r, pos);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l ) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = l + r >> 1;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	void Set(int pos)
	{
		update(1, 1, n, pos);
	}
	int Get(int l, int r)
	{
		return get(1, 1, n, l, r);
	}
};
int ans[100005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++)
		cin >> op[i].x >> op[i].y, op[i].id = i;
	sort(op + 1, op + q + 1);
	Segmentree st(n);
	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		st.Set(r);
		if (last_id[a[r]]) st.Set(last_id[a[r]]);
		last_id[a[r]] = r;
		
		while (op[l].y == r)
		{
			ans[op[l].id] = st.Get(op[l].x, op[l].y);
			l++;
		} 
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

}