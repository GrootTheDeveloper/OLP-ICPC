#include <bits/stdc++.h>
using namespace std;
#define int long long 

int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
main()
{
	int a,b,c,d; cin >> a >> b >> c >> d;
	if (a>b) swap(a,b);
	if (c>d) swap(c,d);
	int x=gcd(a,b);
	int y=gcd(c,d);
	a/=x;
	b/=x;
	c/=y;
	d/=y;
	cout << ((a==c && b==d)? "YES":"NO");

}