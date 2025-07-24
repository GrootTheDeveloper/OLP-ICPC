#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int Min = 0, s = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		s += ai;
		ans = max(ans, s - Min);
		Min = min(Min, s);
	}
	cout << ans;
}
