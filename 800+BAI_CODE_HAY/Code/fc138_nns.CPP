#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
const int N = 2e5 + 5;
const int base = 311;
int n, q;
char a[N], b[N];
int p[N];
struct Segmentree
{
	vector<int> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
	}
	void build(int id, int l, int r, char *a)
	{
		if (l == r) return seg[id] = a[l] - 'a' + 1, void();
		int mid = (l + r) >> 1;
		build(id * 2, l, mid, a);
		build(id * 2 + 1, mid + 1, r, a);
		seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]) % mode;
	}
	void update(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l) return seg[id] = val, void();
		int mid = (l + r) >> 1;
		if (pos <= mid) update(id * 2, l, mid, pos, val);
		else update(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]) % mode;
	}
	int get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = (l + r) >> 1;
		if (v <= mid) return get(id * 2, l, mid, u, v);
		return (get(id * 2, l, mid, u, v) * p[min(v, r) - mid] + get(id * 2 + 1, mid + 1, r, u, v)) % mode;
	}
	void update(int pos, int val)
	{
		update(1, 1, n, pos, val);
	}
	int get(int l, int r)
	{
		return  get(1, 1, n, l, r);
	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], b[n - i + 1] = a[i];
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] * base % mode;
	Segmentree st1(n);
	Segmentree st2(n);
	st1.build(1, 1, n, a);
	st2.build(1, 1, n, b);
	while (q--)
	{
		int kind;
		cin >> kind;
		if (kind == 1)
		{
			int pos;
			char x;
			cin >> pos >> x;
			st1.update(pos, x - 'a' + 1);
			st2.update(n - pos + 1, x - 'a' + 1);
		}
		else
		{
			int l, r; cin >> l >> r;
			int t1 = st1.get(l, r);
			int t2 = st2.get(n - r + 1, n - l + 1);
			//cout << t1 << ' ' << t2 << '\n';
			cout << (t1 == t2? "YES" : "NO") << '\n';	
		}
	}
}
