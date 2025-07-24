#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e15;
const int N = 1e5 + 5;
int ans[N], S[N], C[N], seg[N * 4 * 2];
int m, n, q;
vector<ii> g[N];
struct Query
{
	int L, H, R, id;
	bool operator < (const Query &other) const
	{
		return R < other.R;
	}
}op[N];
struct node
{
	int id, val;
	bool operator < (const node &other) const
	{
		return val < other.val;
	}
}d[N];

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		d[i] = {i, inf};
	d[1].val = 0;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push({0, 1});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, dis = top.fi;
		if (dis > d[u].val) continue;
		for (ii x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[v].val > d[u].val + w)
			{
				d[v].val = d[u].val + w;
				q.push({d[v].val, v});
			}
		}
	}
}

void init(int id, int l, int r)
{
	if (l == r) return seg[id] = inf, void();
	int mid = (l + r) >> 1;
	init(id * 2, l, mid);
	init(id * 2 + 1, mid + 1, r);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = min(seg[id], val), void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return inf;
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	vector<int> b;
	for (int i = 1; i <= n; i++)
		cin >> S[i] >> C[i], b.push_back(S[i]);

	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> op[i].L >> op[i].H >> op[i].R;
		op[i].id = i;
		b.push_back(op[i].L);
		b.push_back(op[i].H);
	}

	dijkstra();
	sort(d + 1, d + n + 1);
	sort(op + 1, op + q + 1);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	int cur_id = 1;
	int Lim = b.size();
	init(1, 1, Lim);
	for (int i = 1; i <= q; i++)
	{	
		while (d[cur_id].val <= op[i].R && cur_id <= n)
		{	
			int u = d[cur_id].id;
			if (S[u] != 0)
			{
				int pos = lower_bound(b.begin(), b.end(), S[u]) - b.begin() + 1;
				update(1, 1, Lim, pos, C[u]);
			}
			cur_id++;
		}
		int lef = lower_bound(b.begin(), b.end(), op[i].L) - b.begin() + 1;
		int rig = lower_bound(b.begin(), b.end(), op[i].H) - b.begin() + 1;
		ans[op[i].id] = get(1, 1, Lim, lef, rig);
	}
	for (int i = 1; i <= q; i++)
		cout << (ans[i] == inf? -1 : ans[i]) << '\n';
}