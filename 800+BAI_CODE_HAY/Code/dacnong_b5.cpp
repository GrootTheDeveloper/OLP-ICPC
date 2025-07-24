#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int ans = 0, cur = 0;
	for (char c : s)
	{
		if (c >= '0' && c <= '9')
			cur = cur * 10 + (c - '0');
		else
			ans += cur, cur = 0;
	}
	cout << ans;
}