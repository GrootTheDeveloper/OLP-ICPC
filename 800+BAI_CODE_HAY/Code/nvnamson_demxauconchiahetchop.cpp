#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,p; cin >> n >> p;
	if (n > 5000) return 0;
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int val = 0;
		for (int j = i; j < n; j++)
			val = (val * 10 + s[j] - '0') % p, res += val == 0;
	}
	cout << res;
}