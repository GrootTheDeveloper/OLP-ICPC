#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		long long ai; cin >> ai;
		if (((n - 1) & i) == i) res = res ^ ai;
	}
	cout << res << endl;
}	