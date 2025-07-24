#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for (int i = 0; i <= n - 3; i++)
		{
			string tmp = s.substr(i, 3);
			ans += (tmp == "pie" || tmp == "map");
			if (i <= n - 5)
			{
				string tmp = s.substr(i, 5);
				ans -= (tmp == "mapie");
			}
		}
		cout << ans << '\n';
	}
}