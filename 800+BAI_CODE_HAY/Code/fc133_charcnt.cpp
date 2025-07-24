#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int seg[N * 4];
char a[N];

void update(int id, int l, int r, int pos, int val)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
		return seg[id] = 0 | (1 << val), void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] | seg[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], update(1, 1, n, i, a[i] - 'a' + 1);
	int q; cin >> q;
	while (q--)
	{
		int kind; cin >> kind;
		if (kind == 1)
		{
			int pos; char c;
			cin >> pos >> c;
			update(1, 1, n, pos, c - 'a' + 1);
		}
		else
		{
			int l, r; cin >> l >> r;
			int x = get(1, 1, n, l, r);
			cout << __builtin_popcount(x) << '\n';
		}
	}

}