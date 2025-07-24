#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[20000], last;
int b[20000], val[20000], seg[80000], pos[20000], pre[20000], mx[20000];
void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void up(int pos, int val)
{
	update(1, 1, last, pos, val);
}
int Get(int l, int r)
{
	return get(1, 1, last, l, r);
}

bool check(int x)
{
	int cnt = 0;
	int p = 1;
	while (p != n)
	{
		int nxt = pre[p] + x;
		int idx = upper_bound(val + 1, val + last + 1, nxt) - val - 1;
		int newp = Get(b[p], idx);
		if (newp <= p) return false;
		p = newp;
		cnt++;
	}
	return cnt <= k;
}
struct node
{
	int val, id;
	bool operator<(const node &other) const
	{
		return val < other.val;
	}
}s[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		s[i].val = s[i - 1].val + a[i];
		s[i].id = i;
	}
	sort(s + 1, s + n + 1);
	int cur = -1e9;
	for (int i = 1; i <= n; i++)
	{
		if (s[i].val != cur)
		{
			last++;
			cur = s[i].val;
		}
		mx[last] = max(mx[last], s[i].id);
		b[s[i].id] = last;
		val[last] = cur;
		pos[s[i].id] = i;
	}
	for (int i = 1; i <= last; i++)
		up(i, mx[i]);
	int l = -1e12, r = 1e12; 
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (!check(l)) l++;
	while (check(l - 1)) l--;
	cout << l;
}
