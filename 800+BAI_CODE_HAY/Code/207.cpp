#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val first
#define id second

ii a[100005];
bool cmp(ii a, ii b)
{
	return (a.val == b.val? a.id < b.id : a.val < b.val);
}

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
		if (pos == l && r == l) return seg[id] = 1, void();
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos);
		update(id *2 + 1, mid + 1, r, pos);
		seg[id] = seg[id  * 2] + seg[id * 2 + 1];
	}
	int get(int id, int l, int r,int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) >> 1;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	void add(int pos) { update(1, 1, n, pos);}
	int get(int pos) { return get(1, 1, n, 1, pos);}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i].val;
		a[i].val += a[i - 1].val;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	Segmentree st(n);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += st.get(a[i].id);
		st.add(a[i].id);
		res += a[i].val >= 0;
	}
	cout << res;
}