#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 2e5 + 5;
const int inf = -1e15;

struct node
{
	int lef, rig, ans;
}seg[maxn * 4], oo;
int h[200005], p[200005], d[200005], l[100005], r[100005];
int n, q;

node Union(node a, node b)
{
	node tmp;
	tmp.lef = max(a.lef, b.lef);
	tmp.rig = max(a.rig, b.rig);
	tmp.ans = max({a.ans, b.ans, a.lef + b.rig});
	return tmp;
}

void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id].lef = 2 * h[pos] - p[pos];
		seg[id].rig = 2 * h[pos] + p[pos];
		seg[id].ans = 0;
		return;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = Union(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return {inf, inf, inf};
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return Union(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void sub()
{
	p[1] = 1;
	for (int i = 2; i <= 2 * n; i++)
	{
		int last = (i - 1) % n;
		if (last == 0) last += n;
		p[i] = p[i - 1] + d[last];
		if (i > n) h[i] = h[i - n];
	}
	int N = 2 * n;
	for (int i = 1; i <= 2 * n; i++)
		update(1, 1, N, i);

	for (int e = 1; e <= q; e++)
	{
		int L = l[e], R = r[e];
		if (R < L) R += n;
		int lim = n + L - 1;
		node tmp = get(1, 1, N, R + 1, lim);
		cout << (tmp.ans == inf? 0 : tmp.ans) << '\n';
		
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	for (int i = 1; i <= q; i++)
		cin >> l[i] >> r[i];
	sub();

}