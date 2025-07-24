#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	int a,b; cin >> a >> b;
	a %= b;
	int res;
	for (int i = 1; i <= 70; i++)
	{
		res = a * 10 / b;
		a = (a * 10) % b;
	}
	cout << res;
}