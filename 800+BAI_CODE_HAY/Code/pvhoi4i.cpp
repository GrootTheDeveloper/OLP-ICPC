#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005];


bool check(int x)
{
	multiset <int> s;
	if (a[1] > x) return false;
	for (int i = 1; i <= n; i++)
	{
		auto it = s.lower_bound(a[i]);
		if (it == s.end()) s.insert(x - a[i]);
		else
		{
			int val = *it - a[i];
			s.erase(it);
			s.insert(val);
		}
		if ((int)s.size() > k) return false;
	}
	return true;
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int l = 1, r = 1e8; 
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (!check(l)) l++;
	while (check(l - 1)) l--;
	cout << l << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("i.inp","r",stdin);
	freopen("i.out","w",stdout);
	int t; cin >> t;
	while (t--) solve();
}