#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode1 = 1e9 + 7, mode2 = 1e9 + 37,base = 311;
const int N = 1e5 + 5;
char a[N];
int seg[N * 4], p[N];

void build(int id, int l, int r)
{
	if (l == r) return seg[id] = a[l], void();
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]);
}
void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id] = a[l], void();
	int mid = (l + r) >> 1;
	if (pos <= mid) update(id * 2, l, mid, pos);
	else update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = (seg[id * 2] * p[r - mid] + seg[id * 2 + 1]);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
	build(1, 1, n);
	set <int> s;
	s.insert(seg[1]);
	while (q--)
	{
		int pos;
		char x;
		cin >> pos >> x;
		a[pos] = x;
		update(1, 1, n, pos);
		s.insert(seg[1]);
	}
	cout << s.size();
}