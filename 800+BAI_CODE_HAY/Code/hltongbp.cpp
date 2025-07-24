#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	freopen("TONGBP.inp","r",stdin);
	freopen("TONGBP.out","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << n*(n+1)*(2*n+1)/6 << '\n';
	}
}