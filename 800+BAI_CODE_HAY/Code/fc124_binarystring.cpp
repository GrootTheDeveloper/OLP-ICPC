#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int l = 0, r = s.size() - 1;
		while (s[l] == '0' && l < (int)s.size()) l++;
		while (s[r] == '0' && r >= 0) r--;
		if (r < 0) 
		{
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = l; i <= r; i++) 
			ans += (s[i] == '0');
		cout << ans << '\n';
	}
}