#include <bits/stdc++.h>
using namespace std;
#define int long long
int bit[100005], a[100005];
int LIM;
void update(int idx, int val)
{
	for (; idx <= LIM; idx += idx & -idx)
		bit[idx] = min(bit[idx], val);
}
int get(int idx)
{
	int ans = 1e9;
	for (; idx; idx -= idx & -idx)
		ans = min(ans, bit[idx]);
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> b = {0};
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= k;
		a[i] += a[i - 1];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	LIM = b.size();
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

	memset(bit, 0x3f, sizeof(bit));
	int rot = lower_bound(b.begin(), b.end(), 0) - b.begin() + 1;
	update(rot, 0);

	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, i - get(a[i]));
		update(a[i], i);
	}
	cout << ans;

}