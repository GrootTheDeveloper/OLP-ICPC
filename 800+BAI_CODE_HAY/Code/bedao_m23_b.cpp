#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n,m; cin >> n >> m;
		if (n%(m+1)!=0) cout << "A";
		else cout << "B";
		cout << '\n';

	}

}