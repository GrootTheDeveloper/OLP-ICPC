#include <bits/stdc++.h>
using namespace std;
#define int long long 

int sumdiv(int n)
{
	int res=0;
	int lim=trunc(sqrt(n));
	for (int i=1;i<=lim;i++) if (n%i==0) res+=(i+n/i);
	res-=((lim*lim==n)? lim:0);
	return res;
}
main()
{
	int n; cin >> n;
	cout << ((sumdiv(n)==2*n)? "YES":"NO");
}