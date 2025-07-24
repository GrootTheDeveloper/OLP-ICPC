#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int res = 0;
	for (int i = 1; i <= 9; i++)
	{
		int ai; cin >> ai;
		if (ai) res = max(res, 3 - ai + 1);
	}
	cout << res;
}