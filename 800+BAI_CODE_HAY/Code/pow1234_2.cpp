#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int power(int a, int b)
{
	int res=1;
	while(b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	int a,m;
	while (t--)
	{
		cin >> a >> m;
		cout << power(a,m*(m+1)/2) << '\n';
	}
}