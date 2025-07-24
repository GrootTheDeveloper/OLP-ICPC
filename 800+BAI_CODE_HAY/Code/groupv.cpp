#include <bits/stdc++.h>
using namespace std;
#define int long long 

int lim;
int bit[100005], sum[100005], b[100005], a[100005];
void ReBit()
{
	memset(sum, 0, sizeof(sum));
	memset(bit, 0, sizeof(bit));
}
void update(int idx, int val)
{
	for (; idx <= lim; idx += -idx & idx)
	{
		bit[idx]++;
		sum[idx]+=val;
	}
}
int getCnt(int idx)
{
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += bit[idx];
	return ans;
}
int getsum(int idx)
{
	int ans = 0;
	for (; idx; idx -= -idx & idx)
		ans += sum[idx];
	return ans;
}
void solve()
{
	unordered_map <int,int> zip;
	set<int> s;
	lim = 0;
	int n, k, R; cin >> n >> k >> R;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int c : s)
		zip[c] = ++lim, b[lim] = c;
	ReBit();
	for (int i = 1; i <= R; i++)
		update(zip[a[i]], a[i]);

	for (int i = R + 1; i <= n; i++)
	{
		update(zip[a[i]], a[i]);
		int ans = 0, l = 0, r = 1e16;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int pos = lower_bound(b + 1, b + lim + 1, mid) - b - 1;
			int S = (getCnt(lim) - getCnt(pos)) * mid + getsum(pos);
			if (S >= mid * k) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << ' ';
	}
	cout << '\n';
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}