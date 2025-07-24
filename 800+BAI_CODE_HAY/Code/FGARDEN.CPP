#include <bits/stdc++.h>
using namespace std;
int a[3000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	multiset<int> s;
	int l = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		s.insert(a[i]);
		while (*s.rbegin() - *s.begin() > k)
			s.erase(s.find(a[l++]));
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}