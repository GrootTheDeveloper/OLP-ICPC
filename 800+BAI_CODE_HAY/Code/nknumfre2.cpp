#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int dn(int n)
{
	int res=0;
	while (n) res=res*10+n%10,n/=10;
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a,b; cin >> a >> b;
	int res=0;
	for (int i=a;i<=b;i++)
	res+=(gcd(i,dn(i))==1);
	cout << res;
}