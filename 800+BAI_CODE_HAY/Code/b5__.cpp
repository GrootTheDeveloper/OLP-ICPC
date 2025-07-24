#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define x first
#define w second 
ii a[500005];
int val[500005], n;
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
	void push(int id, int l, int r)
	{
		if (lazy[id])
		{
			seg[id * 2] += lazy[id];
			seg[id * 2 + 1] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
			lazy[id * 2] += lazy[id];
			lazy[id] = 0;
		}
	}
	void Up(int id, int l, int r, int u, int v, int val)
	{
		if (u > r || v < l) return;
		if (u <= l && r <= v)
		{
			seg[id] += val;
			lazy[id] += val;
			return;
		}
		push(id, l, r);
		int mid = l + r >> 1;
		Up(id * 2, l, mid, u, v, val);
		Up(id * 2 + 1, mid + 1, r, u, v, val);
		seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	}
	int Get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		push(id, l, r);
		int mid = l + r >> 1;
		return max( Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
	}
	void build(int id, int l, int r)
	{
		if (l == r) return seg[id] = val[l], void();
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	}
	void build()
	{
		build(1, 1, n);
	}
	void update(int pos, int val)
	{
		Up(1, 1, n, pos, n, val);
	}

	int get(int pos)
	{
		return Get(1, 1, n, pos, n);
	}
};

void sub1()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int val = 0, kc = 0;
		for (int j = i; j <= n; j++)
		{
			val += a[j].w;
			kc   = a[j].x - a[i].x;
			res = max(res, val - kc);
		}
	}
	cout << res;
}

void sub2()
{
	val[1] = a[1].w;
	int sum = 0, kc = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i].w;
		kc   = a[i].x - a[1].x;
		val[i] = sum - kc;
	}
	Segmentree st(n);
	st.build();
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, st.get(i));
		if (i < n)
			st.update(i + 1, (a[i + 1].x - a[i].x) - a[i].w);
	}
	cout << res;

}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].x >> a[i].w;
	sort(a + 1, a + n + 1);
	if (n < 5000) sub1();
	else sub2();
}