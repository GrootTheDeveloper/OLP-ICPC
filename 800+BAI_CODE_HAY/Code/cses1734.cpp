#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x, y, id;
}query[200005];
int ans[200005], a[200005];
unordered_map <int, int> f;
struct Segmentree
{
	vector <int> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
	}
	void update(int id, int l, int r, const int &pos)
	{
		if (pos > r || pos < l) return;
		if (l == r && l == pos) return seg[id] = 1 - seg[id], void();
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
	void update(const int &pos)
	{
		update(1, 1, n, pos);
	}
	int get(int l, int r)
	{
		return get(1, 1, n, l, r);
	}
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= q; i++)
		cin >> query[i].x >> query[i].y, query[i].id = i;
	
	sort(query + 1, query + q + 1,[](node a, node b)
	{
		return a.y < b.y;
	});
	
	int l = 1;
	Segmentree st(n);
	for (int i = 1; i <= q; i++)
	{
		while (l <= query[i].y)
		{
			st.update(l);
			if (f[a[l]]) st.update(f[a[l]]);
			f[a[l]] = l;
			++l;
		}
		ans[query[i].id] = st.get(query[i].x, query[i].y);
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}