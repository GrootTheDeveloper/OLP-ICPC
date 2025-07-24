#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool check(int n)
{
	int lim=trunc(sqrt(n)),divs=0;
	for (int i=2;i<=lim;i++)
		if (n%i==0) divs+=i+n/i;
	divs++;
	if (lim*lim==n) divs-=lim;
	return divs>n;
}
main()
{
	int l,r; cin >> l >> r;
	int res=0;
	for (int i=l;i<=r;i++)
	{
		res+=check(i);
	}
	cout << res;
}