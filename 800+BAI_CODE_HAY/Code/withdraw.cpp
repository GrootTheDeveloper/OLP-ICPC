#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n; t; --t)
	{
		cin >> n;
		int res = 0;
		res += n / 100; n %= 100;
		res += n / 20 ; n %=  20;
		res += n / 10 ; n %=  10;
		res += n / 5  ; n %=   5;
		res += n / 1  ;
		cout << res << '\n';
	}
}