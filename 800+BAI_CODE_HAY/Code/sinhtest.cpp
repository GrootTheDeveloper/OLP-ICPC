#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	freopen("input.inp","w",stdout);
	int n, m; cin >> n >> m;
	cout << n << ' ' << m << '\n';
	for (int i=1;i<=m;i++)
	{
	    int val = rand() % (n - 1) + 1;
		cout << val << ' ';
	}

}
