#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int n; cin >> n;
	int res = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		char ai; cin >> ai;
		if (ai == '1') sum += 1;
		else sum = 0;
		res += sum;
	}
	cout << res;
}