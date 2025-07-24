#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

struct node 
{
	int ans, pre, suf, sum;
}seg[N * 4];
int a[N];
node mer(node &a, node &b)
{
	node res;
	res.ans = max({a.ans, b.ans, a.suf + b.pre});
	res.pre = max(a.pre, a.sum + b.pre);
	res.suf = max(b.suf, b.sum + a.suf);
	res.sum = a.sum + b.sum;
	return res;
}
void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id].ans = seg[id].pre = seg[id].suf = seg[id].sum = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = mer(seg[id * 2], seg[id * 2 + 1]);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], update(1, 1, n, i, a[i]);
	while (m--)
	{
		int k, x; cin >> k >> x;
		update(1, 1, n, k, x);
		cout << max(seg[1].ans, 0ll) << '\n';
	}
}