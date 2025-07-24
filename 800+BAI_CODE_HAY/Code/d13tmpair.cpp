#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
	int n; cin >> n;
	int lim=trunc(sqrt(n));
	int res=-1;
	for (int i=1;i<=lim;i++) 
	if (n%i==0) res+=2;
	if (lim*lim==n) res--;
	res*=2;
	if (n%(n/2)==0) res--;
	cout << res;
}