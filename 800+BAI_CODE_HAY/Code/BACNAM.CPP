#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans1 = 0, ans2 = 0;
	map<int,bool> mark;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		if (ai & 1)
			ans1 += (!mark[ai - 2]);
		else
			ans2 += (!mark[ai - 2]);
		mark[ai] = true;
	}
	cout << ans1 << '\n' << ans2;
}