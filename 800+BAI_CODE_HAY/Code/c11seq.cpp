#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int seg[N * 4], b[N], val[N], pos[N];
int n, L, R;
void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id]++, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void Up(int pos) { update(1, 1, n, pos);}
int Get(int l, int r) { return get(1, 1, n, l, r);}
struct node
{
	int val, id;
	bool operator<(const node &other) const
	{
		return val < other.val;
	}
}s[100005];

void sub1()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			res += (s[j].val - s[i - 1].val >= L && s[j].val - s[i - 1].val <= R);
	cout << res << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		s[i].val = s[i - 1].val + ai;
		s[i].id = i;
	}
	//sub1();
	int last = 0, cur = -1e15;
	sort(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i].val != cur)
		{
			last++;
			cur = s[i].val;
			val[last] = cur;
		} 
		b[s[i].id] = last;
		pos[s[i].id] = i;	
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int lef = s[pos[i]].val - R;
		int rig = s[pos[i]].val - L;
		int pos1 = lower_bound(val + 1, val + last + 1, lef) - val;
		int pos2 = upper_bound(val + 1, val + last + 1, rig) - val - 1;
		res += (s[pos[i]].val >= L && s[pos[i]].val <= R);
		/*if (val[pos1] >= lef && val[pos2] <= rig && pos1 <= pos2)*/ res += Get(pos1, pos2); 
		Up(b[i]);
	}
	cout << res;
}