#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b, c; cin >> a >> b >> c;
		int ans = 0;
		for (int i = -1e6; i <= 1e6; i++)
			ans += (a * (i * i) + b * i + c == 0);
		cout << ans << '\n';
	}
}