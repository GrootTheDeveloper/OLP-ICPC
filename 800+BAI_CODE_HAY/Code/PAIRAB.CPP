#include <bits/stdc++.h>
using namespace std;

int bit[300005], a[200005], b[200005], LIM;

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
void update(int idx)
{
	for (; idx <= LIM; idx += idx & -idx)
		bit[idx]++;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	vector<int> lst;
	for (int i = 1; i <= n; i++)
		lst.push_back(a[i] - b[i]);
	sort(lst.begin(), end(lst));
	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	LIM = lst.size() + 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = upper_bound(lst.begin(), lst.end(), b[i] - a[i]) - lst.begin() + 1;
		ans += get(pos, LIM);
		pos = lower_bound(lst.begin(), lst.end(), a[i] - b[i]) - lst.begin() + 1;
		update(pos);
	}
	cout << ans;
}