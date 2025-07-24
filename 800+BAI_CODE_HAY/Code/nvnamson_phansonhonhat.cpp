#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	double a,b,c; cin >> a >> b >> c;
	double top = 0.0, down = 1.0;
	if ( a / b > top / down) top = a, down = b;
	if ( b / a > top / down) top = b, down = a;
	if ( a / c > top / down) top = a, down = c;
	if ( c / a > top / down) top = c, down = a;
	if ( b / c > top / down) top = b, down = c;
	if ( c / b > top / down) top = c, down = b;
	int gcd = __gcd((int)top,(int)down);
	cout << (int)top/gcd + (int)down/gcd;
}