#include <bits/stdc++.h>
using namespace std;

int n, a[100005], bit[100005], pos[100005];
void update(int idx, int val)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}
int get(int l, int r)
{
	l--;
	int ans = 0;
	for (; r; r -= r & -r)
		ans += bit[r];
	for (; l; l -= l & -l)
		ans -= bit[l];
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		pos[ai] = i;
		update(i, 1);
	}
	for (int i = 1;  i <= n / 2; i++)
	{
		cout << get(1, pos[i] - 1) << ' ';
		update(pos[i], -1);
		cout << get(pos[n - i + 1] + 1, n) << ' ';
		update(pos[n - i + 1], -1);
	}
	if (n & 1) cout << get(1, pos[n / 2 + 1] - 1);
}