#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[100005], bit[100005];
int n, q;
void update(int idx, int val)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}
int get(int idx1, int idx2)
{
	int ans = 0;
	idx1--;
	for (; idx1; idx1 -= idx1 & -idx1)
		ans -= bit[idx1];
	for (; idx2; idx2 -= idx2 & -idx2)
		ans += bit[idx2];
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], update(i, a[i]);

	while (q--)
	{
		int kind, l, r; cin >> kind >> l >> r;
		if (kind == 0)
		{
			int val1 = a[l], val2 = a[r];
			swap(a[l], a[r]);
			update(l, val2 - val1);
			update(r, val1 - val2);
		} else cout << get(l, r) << '\n';
	}
}