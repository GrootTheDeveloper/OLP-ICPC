#include <bits/stdc++.h>
using namespace std;
#define int long long 

int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int bcnn(int a, int b)
{
	return a*b/gcd(a,b);
}
int calc(int i, int l, int r)
{
	return r/i-(l-1)/i;
}
main()
{
	freopen("b1.inp","r",stdin);
	freopen("b2.out","w",stdout);
	int l,r,a,b;
	cin >> l >> r >> a >> b;
	int k=bcnn(a,b);
	int res=0;
	res+=calc(a,l,r);
	res+=calc(b,l,r);
	res+=calc(k,l,r);
	cout << res;
}