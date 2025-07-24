#include <bits/stdc++.h>
using namespace std;
#define int long long
long double a;
const long double pi=3.14159265358979323846;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	cout << fixed << setprecision(6);
	while (t--)
	{
		cin >> a;
		cout << a*a*pi-2*a*a << '\n';
	}
}