#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define ii pair<int,int>
const int mode = 20071008;
struct input
{
	int val, id;
	bool operator < (const input &other) const
	{
		return (val == other.val? id > other.id : val < other.val);
	}
}a[100005];
int n;
ii seg[400005];

ii compare(ii a, ii b)
{
	return (a.fi == b.fi? make_pair(a.fi, (a.se + b.se) % mode) : max(a, b));
}

void update(int id, int l, int r, int pos, ii val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = compare(seg[id * 2], seg[id * 2 + 1]);
}
ii get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return {0, 0};
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return compare(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void update(int pos, ii val)
{
	update(1, 1, n, pos, val);
}
ii get(int pos)
{
	return get(1, 1, n, 1, pos);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].val, a[i].id = i;

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
	{
		ii cur = {1, 1};
		ii tmp = get(a[i].id - 1);
		tmp.fi += 1;
		cur = max(cur, tmp);
		update(a[i].id, cur);
	}

	cout << seg[1].se;
}