#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0, sum = 0, mi = 0, res = 0;
	for (char c : s)
	{
		int ai = c - '0';
		if (ai) sum--, ans++;
		else sum++;
		res = max(res, sum - mi);
		mi = min(mi, sum);
	}
	if (res > 0) ans += res;
	cout << ans;
}