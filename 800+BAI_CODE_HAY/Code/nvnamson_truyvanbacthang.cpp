#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tup tuple<int,int,int>

int pre[100005], a[100005];
struct Segmentree
{
	vector <int> seg;
	int n; 
	Segmentree (int _n)
	{
		n = _n;
		seg.resize(n * 4 + 5);
		build(1, 1, n);
	}
	void build(int id, int l, int r)
	{
		if (l == r) return seg[id] = a[l], void();
		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		seg[id] = seg[id * 2] + (mid - l + 1) * (pre[r] - pre[mid]) + seg[id * 2 + 1];
	}
	tup mer(tup a, tup b)
	{
		int val1, val2, sum1, sum2, len1, len2;
		tie(val1, len1, sum1) = a;
		tie(val2, len2, sum2) = b;
		return {val1 + val2 + sum2 * len1, len1 + len2, sum1 + sum2};
	}
	tup get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return {0,0,0};
		if (u <= l && r <= v) return {seg[id], r - l + 1, pre[r] - pre[l - 1]};
		int mid = (l + r) >> 1;
		return mer(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
	}
	int Ans(int l, int r)
	{
		tup x = get(1, 1, n, l, r);
		int a, b, c;
		tie(a, b, c) = x;
		return a;
	}
};


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	Segmentree st(n);
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << st.Ans(l, r) << '\n';
	}

}