#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j <= i; j++)
		if (i % j != 0) 
		{
			cout << j << ' ';
			break;
		}
	}
}