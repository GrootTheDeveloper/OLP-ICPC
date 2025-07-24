#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int base = 311;
const int mode = 1e9 + 7;
long long seg[N * 4], Hash[2][N], p[N];
signed lazy[N * 4], kind[N];
int n, q;
int l[N], r[N], x[N];
char a[N], b[N];
void sub1()
{
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	for (int t = 1; t <= q; t++)
	{
		if (kind[t] == 1)
		{
			for (int i = l[t]; i <= r[t]; i++)
				b[i] = '0' + x[i];
		} else
		{
			bool ans = 1;
			for (int i = 0; i < x[t]; i++)
				if (b[l[t] + i] != b[r[t] + i]) ans = 0;
			cout << ans;
		}
	}
	cout << '\n';
}

void build(int id, int l, int r)
{
	if (l == r) return seg[id] = a[l], void();
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]);
}

void down(int id, int l, int r)
{
	if (lazy[id] != -1)
	{
		int mid = (l + r) >> 1;
		signed e = lazy[id];
		seg[id * 2] = Hash[e][mid - l + 1];
		seg[id * 2 + 1] = Hash[e][r - mid];
		lazy[id * 2] = lazy[id * 2 + 1] = e;
		lazy[id] = -1;
	}
}
void update(int id, int l, int r, const int &u, const int &v, const int &val)
{
	if (u > r || v < l) return;
	if (u <= l && r <= v)
	{
		seg[id] = Hash[val][r - l + 1];
		lazy[id] = val;
		return;
	}
	int mid = (r + l) >> 1;
	down(id, l, r);
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) 
		return seg[id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	if (v <= mid) return get(id * 2, l, mid, u, v);
	return (get(id * 2, l, mid, u, v) * p[min(v, r) - mid] + get(id * 2 + 1, mid + 1, r, u, v));
}

void sub2()
{
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
	memset(lazy, -1, sizeof(lazy));
	for (int i = 1; i <= n; i++)
	{
		Hash[0][i] = (Hash[0][i - 1] * base + '0');
		Hash[1][i] = (Hash[1][i - 1] * base + '1');
	}
	build(1, 1, n);
	for (int t = 1; t <= q; t++)
	{
		if (kind[t] == 1)
			update(1, 1, n, l[t], r[t], x[t]);
		else
		{
			long long t1 = get(1, 1, n, l[t], l[t] + x[t] - 1);
			long long t2 = get(1, 1, n, r[t], r[t] + x[t] - 1);
			cout << (t1 == t2);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
		a[i] = s[i - 1];
	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> kind[i] >> l[i] >> r[i] >> x[i];
	//sub1();
	sub2();

}