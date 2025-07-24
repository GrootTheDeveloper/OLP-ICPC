#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = -1e15;
const int N = 4e5 + 5;
struct node
{
	int ans, sum, suf, pre, l, r, ids, idp;
}seg[N * 4];
node oo;
int a[N], b[N], query[N + 100005], l[N + 100005], r[N + 100005], x[N + 100005];

node comb(node a, node b)
{
	node ans = a;
	ans.sum = (a.sum == inf || b.sum == inf? inf : a.sum + b.sum);
	ans.suf = b.suf;
	ans.ids = b.ids;
	if (ans.ans < b.ans)
	{
		ans.ans = b.ans;
		ans.l = b.l;
		ans.r = b.r;
	}
	if (ans.ans < a.suf + b.pre)
	{
		ans.ans = a.suf + b.pre;
		ans.l = a.ids;
		ans.r = b.idp;
	}
	if (ans.pre < a.sum + b.pre)
	{
		ans.pre = a.sum + b.pre;
		ans.idp = b.idp;
	}
	if (ans.suf < a.suf + b.sum)
	{
		ans.suf = a.suf + b.sum;
		ans.ids = a.ids;
	}
	return ans;
}

void init(int id, int l, int r)
{
	if (l == r)
	{
		seg[id].ans = seg[id].sum = seg[id].suf = seg[id].pre = inf;
		seg[id].l = seg[id].r = seg[id].ids = seg[id].idp = l;
		return;
	}
	int mid = (l + r) >> 1;
	init(id * 2, l, mid);
	init(id * 2 + 1, mid + 1, r);
	seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
}
void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id].sum = seg[id].ans = seg[id].pre = seg[id].suf = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return oo;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return comb( get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
#define ii pair<int,int>
#define lef first
#define rig second
ii ans[500005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("maxsum.inp","r",stdin);
	freopen("maxsum.out","w",stdout);
	int o; cin >> o;
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	iota(b + 1, b + n + 1, 1);
	sort(b + 1, b + n + 1, [](int x, int y)
	{
		return a[x] > a[y];
	});
	for (int i = 1; i <= q; i++)
		cin >> l[i] >> r[i] >> x[i];
	iota(query + 1, query + q + 1, 1);
	sort(query + 1, query + q + 1,[](int a, int b)
	{
		return x[a] > x[b];
	});
	oo.ans = oo.suf = oo.pre = oo.sum = inf;
	init(1, 1, n);
	int id = 1;
	for (int i = 1; i <= q; i++)
	{
		while (a[b[id]] >= x[query[i]] && id <= n)
		{
			update(1, 1, n, b[id], a[b[id]]);
			//cout << "(" << b[id] << ' ' << a[b[id]] << ") ";
			id++;
		}
		//cout << seg[1].ans << ' ';
		node tmp = get(1, 1, n, l[query[i]], r[query[i]]);
		//cout << tmp.ans << ' ';
		if (tmp.ans != inf)
		{
			ans[query[i]].lef = tmp.l;
			ans[query[i]].rig = tmp.r;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		if (ans[i].lef) cout << ans[i].lef << ' ' << ans[i].rig;
		else cout << 0;
		cout << '\n';
	}
}