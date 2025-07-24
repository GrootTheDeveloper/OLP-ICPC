#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int cur = 0, ans = 0;
	for (char c : s)
	{
		if (c == 'D')
			ans += (++cur);
		else 
			cur = 0;
	}
	cout << ans;
}