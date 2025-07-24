#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, q;
int a[300005], b[300005];

struct node
{
	int fi, se;
	node (int x, int y)
	{
		fi = x;
		se = y;
	}
	bool operator<(const node &other) const
	{
		return (se - fi == other.se - other.fi? fi > other.fi : se - fi < other.se - other.fi);
	}
};

int ans[300005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("LONELY.INP","r",stdin);
	freopen("LONELY.OUT","w",stdout);
	cin >> m >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], ans[i] = a[i];
	int mx = 0;
	for (int i = 1; i <= q; i++) cin >> b[i], mx = max(mx, b[i]);
	if (mx > 3e5) return 0;

	priority_queue <node> pq;
	a[n + 1] = m + 1;
	for (int i = 0; i <= n; i++)
		if (a[i + 1] - a[i] > 1)
		{
			node x(0,0);
			x.fi = a[i] + 1;
			x.se = a[i + 1] - 1;
			pq.push(x);
		}
	for (int i = n + 1; i <= mx; i++)
	{
		auto x = pq.top(); pq.pop();
		int l = x.fi, r = x.se;
		int mid = (l + r) / 2;
		ans[i] = mid;
		if (mid - 1 >= l) pq.push(node(l, mid - 1));
		if (mid + 1 <= r) pq.push(node(mid + 1, r));
	}
	for (int i = 1; i <= q; i++)
		cout << ans[b[i]] << '\n';
}
