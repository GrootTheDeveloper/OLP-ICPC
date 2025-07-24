#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define TASK "TOY"
const int N = 2e6; 
int seg[N * 4], a[N];
int n, q;
void update(int id, int l, int r, const int &pos, const int &val)
{
	if (pos > r || pos < l) return;
	if (l == r && l == pos) return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, const int &u, const int &v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void Up(const int &pos, const int &val)
{
	update(1, 1, n, pos, val);
}
int Sum(const int &l, const int &r)
{
	return get(1, 1, n, l, r);
}
struct node
{
	int kind, u, v;
}op[N];



void sub1()
{
	for (int i = 1; i <= n; i++) Up(i, a[i]);
	for (int o = 1; o <= q; o++)
	{
		int kind = op[o].kind, u = op[o].u, v = op[o].v;
		if (kind == 1)
			Up(u, v);
		else
		{
			int l = u, r = v;
			int SUM = Sum(u, v), sum = SUM / 2;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (Sum(u, mid) < sum) l = mid + 1;
				else r = mid - 1;
			}
			int ans = 1e16;
			for (int i = max(l - 1, u); i <= min(v, l + 1); i++)
				ans = min(ans, abs(SUM - 2 * Sum(u, i)));
			
			cout << ans << '\n';

		}
	}
}
int pre[N];
void sub2()
{
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int o = 1; o <= q; o++)
	{
		int u = op[o].u, v = op[o].v;
		int l = u, r = v;
		int SUM = pre[v] - pre[u - 1], sum = SUM / 2;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (pre[mid] - pre[u - 1] < sum) l = mid + 1;
			else r = mid - 1;
		}
		int ans = 1e16;
		for (int i = max(l - 1, u); i <= min(v, l + 1); i++)
			ans = min(ans, abs(SUM - 2 * (pre[i] - pre[u - 1])));
		cout << ans << '\n';
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen(TASK".INP","r",stdin);
	freopen(TASK".OUT","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= q; i++)
		cin >> op[i].kind >> op[i].u >> op[i].v, cnt += (op[i].kind == 1);
	if (cnt == 0) sub2();
	else if (n <= 2e5) sub1();
	
}