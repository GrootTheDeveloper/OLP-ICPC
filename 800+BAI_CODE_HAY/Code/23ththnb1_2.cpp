#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int l,r,t; cin >> l >> r >> t;
	int a,b;
	a=t-r;
	b=r;
	if (a<=l)
	{
		b-=(l-a);
		a=l;
	}
	else 
	if (b<=a) return cout << 0,0;
	cout << (b-a+1)/2;
}