#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005];
struct Segmentree
{
	struct node
	{
		int ans, pre, suf, sum;
	};
	vector <node> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.resize(n * 4 + 5);
		build(1, 1, n);
	}
	node comb(node a, node b)
	{
		node ans;
		ans.ans = max({a.ans, b.ans, a.suf + b.pre});
		ans.pre = max({a.pre, a.sum + b.pre});
		ans.suf = max({b.suf, b.sum + a.suf});
		ans.sum = (a.sum < 0 || b.sum < 0? -1e15 : a.sum + b.sum);
		return ans;
	}
	void build(int id, int l, int r)
	{
		if (l == r)
		{
			seg[id].sum = seg[id].suf = seg[id].pre = seg[id].ans = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
	}
	void update(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l)
		{
			seg[id].sum = seg[id].suf = seg[id].pre = seg[id].ans = val;
			return;
		}
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos, val);
		update(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
	}	
};



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	Segmentree st(n);
	for (int i = 1; i < n; i++)
	{
		int pos; cin >> pos;
		st.update(1, 1, n, pos, -1e15);
		cout << st.seg[1].ans << '\n';
	}
	cout << 0;
}



