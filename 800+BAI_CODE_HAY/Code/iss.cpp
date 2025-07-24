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
		if (l == r && pos == l) return seg[id] = val, void();
		int mid = l + r >> 1;
		update(id << 1, l, mid, pos, val);
		update(id << 1 | 1, mid + 1, r, pos, val);
		seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = l + r >> 1;
		return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
	}
	void Add(int pos, int val) { update(1, 1, n, pos, val);}
	int Query(int pos) { return get(1, 1, n, 1, pos);}
};


struct node
{
	int val, id, w;
	bool operator<(const node &other) const
	{
		return (val == other.val? id > other.id : val < other.val);
	}
} a[100005];
int n;

void solve()
{
	int res = 0;
	Segmentree st(n);
	for (int i = 1; i <= n; i++)
	{
		int ans = st.Query(a[i].id) + a[i].w;
		res = max(res, ans);
		st.Add(a[i].id, ans);
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].val, a[i].id = i;
	for (int i = 1; i <= n; i++)
		cin >> a[i].w;
	sort(a + 1, a + n + 1);
	solve();
}