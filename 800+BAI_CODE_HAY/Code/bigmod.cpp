#include <bits/stdc++.h>
using namespace std;
#define int long long 

int power(int a, int b, int mode)
{
	int res=1;
	while (b!=0)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a,b,mode; cin >> a >> b >> mode;
	cout << power(a,b,mode);
}