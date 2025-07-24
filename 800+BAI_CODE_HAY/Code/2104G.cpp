#include <bits/stdc++.h>
using namespace std;


int n, k;
int a[100005], bit[100005], pos[100005];
vector<int> g[100005];
void update(int idx, int val)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] = max(bit[idx], val);
}
int get(int idx)
{
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans = max(ans, bit[idx]);
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		pos[ai] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int val = max(1, a[i] - k); val <= min(n, a[i] + k); val++)
			g[a[i]].push_back(pos[val]);
		sort(g[a[i]].begin(), g[a[i]].end(), greater<int>());
	}


	for (int i = 1; i <= n; i++)
	for (int idx : g[a[i]])
			update(idx, get(idx - 1) + 1);
	cout << get(n);

}