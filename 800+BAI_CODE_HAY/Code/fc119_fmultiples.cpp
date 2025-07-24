#include <bits/stdc++.h>
using namespace std;
//#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;

	int n = s.size();
	s = " " + s;

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = s[i] - '0';
		ans += (cur % 4 == 0);
		if (i > 1)
		{
			int last = s[i - 1] - '0';
			if ((last * 10 + cur) % 4 == 0) ans += i - 1;
		}
	}
	cout << ans;
}