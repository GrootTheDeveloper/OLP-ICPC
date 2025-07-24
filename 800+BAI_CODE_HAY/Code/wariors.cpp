#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int res = 0;
	unordered_map <int, bool> f;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		while (f[ai]) ai *= 2;
		f[ai] = true;
		res = max(res, ai);
		cout << res << ' ';

	}
}