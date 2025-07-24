#include <bits/stdc++.h>
using namespace std;
#define int long long 
const long double pi =  3.1415926535897;

signed main()
{
	long double a, alpha, h;
	cin >> a >> alpha >> h;
	alpha = alpha * pi / 180;
	cout << fixed << setprecision(3) <<  tan(alpha) * a + h;
}