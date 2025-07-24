#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n,pos1,posn; t; t--)
	{
		cin >> n;
		for (int i = 1,val; i <= n; i++)
		{
			cin >> val;
			pos1 = ((val == 1)? i : pos1);
			posn = ((val == n)? i : posn);
		}
		if (pos1 > posn) swap(pos1,posn);
		cout << min({n - pos1 + 1, posn, pos1 + n - posn +1}) << '\n';
	}
}