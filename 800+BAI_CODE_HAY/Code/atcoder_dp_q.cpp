#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[200005], h[200005];

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
		if (l == r && l == pos) return seg[id] = val, void();
		int mid = (l + r ) >> 1;
		update(id * 2, l, mid, pos, val);
		update(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) >> 1;
		return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
	}
	void Add(int pos, int val)
	{
		update(1, 1, n, pos, val);
	}
	int Ans(int pos) {return get(1, 1, n, 1, pos);}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	Segmentree st(n);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int val = a[i] + st.Ans(h[i]);
		res = max(res, val);
		st.Add(h[i], val);
	}
	cout << res;
}