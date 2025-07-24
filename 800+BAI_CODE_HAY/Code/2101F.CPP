#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

struct node 
{
	long long val, id;
	node() : val(0), id(0) {};
	node(int a, int b) : val(a), id(b) {};
	node operator + (const node &other) 
	{
		return (val >= other.val? node(val, id) : other);
	}
};

int a[N];
node seg[N * 4];
long long lazy[N * 4], pre[N];


void down(int id, int l, int r)
{
	if (lazy[id])
	{
		int tmp = lazy[id];
		seg[id * 2].val += tmp;
		seg[id * 2 + 1].val += tmp;
		lazy[id * 2] += tmp;
		lazy[id * 2 + 1] += tmp;
		lazy[id] = 0;
	}
}
void update(int id, int l, int r, int u, int v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		seg[id].val += val;
		lazy[id] += val;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update_node(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id] = node(val, pos);
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update_node(id * 2, l, mid, pos, val);
	update_node(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void solve()
{
	int n, r; cin >> n >> r;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(lazy, 0, sizeof(lazy));
	for (int i = 1; i <= n; i++)
		update_node(1, 1, n, i, 0);

	for (int i = 1; i <= n; i++)
		update(1, 1, n, max(1ll, i - r), min(n, i + r), a[i]);
	long long ans = 0;
	int cnt = 0;
	while (seg[1].val >= 0)
	{
		++cnt;
		ans += seg[1].val;
		int pos = seg[1].id;
		for (int i = max(1ll, pos - r); i <= min(n, pos + r); i++)
		{
			update(1, 1, n, max(1ll, i - r), min(n, i + r), -a[i]);
			update_node(1, 1, n, i, -1e9);	
		}
	}
	cout << ans + (cnt == 0? seg[1].val : 0) << '\n';
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();	
}

// 3 
// 5 1 
// 1 0 -10 0 1 
// 5 1
// 1 1 1 1 1
// 5 1
// -1 -1 -1 -1 -1