#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5 + 31 + 01 + 2007;

struct node
{
	long long ans, sum, pre, suf;
	node () : ans(0), sum(0), pre(0), suf(0){}
	node (ll a, ll b, ll c, ll d) : ans(a), sum(b), pre(c), suf(d){}
	node operator + (const node &other)
	{
		return node(max({ans, other.ans, suf + other.pre}), sum + other.sum, max(pre, sum + other.pre), max(other.suf, other.sum + suf));
	}
};
struct input
{
	int val, id;
	bool operator < (const input &other) const
	{
		return val < other.val;
	}
} a[100005], Q[100005];

int ans[100005];
node seg[N * 4];
const node oo = node(-1e9, -1e9, -1e9, -1e9);

void init(int id, int l, int r)
{
	if (l == r)
		return seg[id] = oo, void();
	int mid = (l + r) >> 1;
	init(id * 2, l, mid);
	init(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && l == pos)
		return seg[id] = node(1, 1, 1, 1), void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i].val, a[i].id = i;

	for (int i = 1; i <= q; i++)
		cin >> Q[i].val, Q[i].id = i;

	sort(a + 1, a + n + 1);
	sort(Q + 1, Q + q + 1);
	init(1, 1, n);

	int cur = 1;
	for (int i = 1; i <= q; i++)
	{
		while (a[cur].val <= Q[i].val && cur <= n)
			update(1, 1, n, a[cur++].id);
		ans[Q[i].id] = (seg[1].ans > 0? seg[1].ans : 0);
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';

}