#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int m,n,k; t; t--)
	{
		cin >> m >> n >> k;
		cout << ((k == m*n - 1)? "YES":"NO") << '\n';
	}
}