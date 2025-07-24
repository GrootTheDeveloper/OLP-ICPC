#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a,b;
int gcd(int a, int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int k=gcd(abs(a),abs(b));
		a/=k;b/=k;
		if (a+b==0) cout << "0 0"; 
		else if (a+b<0) cout << a*(-1) << ' ' << b*(-1);
		else if (a+b>0) cout << a << ' ' << b;
		cout << '\n';
	}
}