#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
unordered_map <int, int> zip;
int bit[N * 4], u[N], v[N], a[N], b[N * 4];
int lim;
char kind[N];

void update(int idx, int val)
{
	for (; idx <= lim; idx += (idx&(-idx)))
		bit[idx] += val;
}
int get(int l, int r)
{
	int ans = 0;
	l--;
	for (; r; r -= (r&(-r))) ans += bit[r];
	for (; l; l -= (l&(-l))) ans -= bit[l];
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	set <int> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s.insert(a[i]);
	for (int i = 1; i <= q; i++)
	{
		cin >> kind[i] >> u[i] >> v[i];
		if (kind[i] == '!') s.insert(v[i]);
	}
	for (int x : s) zip[x] = ++lim, b[lim] = x;

	for (int i = 1; i <= n; i++)
		a[i] = zip[a[i]];
	for (int i = 1; i <= q; i++)
	if (kind[i] == '!') v[i] = zip[v[i]];

	for (int i = 1; i <= n; i++)
		update(a[i], 1);

	for (int i = 1; i <= q; i++)
	{
		if (kind[i] == '!')
		{
			update(a[u[i]], -1);
			a[u[i]] = v[i];
			update(v[i], 1);
		}
		if (kind[i] == '?')
		{
			int l = lower_bound(b + 1, b + lim + 1, u[i]) - b;
			int r = upper_bound(b + 1, b + lim + 1, v[i]) - b - 1;
			cout << get(l, r) << '\n';
		}
	}
}