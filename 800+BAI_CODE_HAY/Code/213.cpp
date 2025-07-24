#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
struct node
{
	int ans, pre, suf, sum;
}seg[N * 4];
int n, a[N], pre[N * 4];


node join(node a, node b)
{
	node res;
	res.ans = max({a.ans, b.ans, a.suf + b.pre});
	res.suf = max(a.suf + b.sum, b.suf);
	res.pre = max(a.pre, a.sum + b.pre);
	res.sum = a.sum + b.sum;
	return res;
}
void build(int id, int l, int r)
{
	if (l == r)
	{
		seg[id].sum = seg[id].ans = seg[id].pre = seg[id].suf = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = join(seg[id * 2], seg[id * 2 + 1]);
}
node oo;
node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return oo;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) / 2;
	return join(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	oo.ans = oo.suf = oo.pre = -1e15;
	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << get(1, 1, n, l, r).ans << '\n';
	}


}