#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double 
double f[10005];
void o_o()
{
	f[1]=sqrt(2);
	for (int i=2;i<=10000;i++) f[i]=sqrt(2+f[i-1]);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	o_o();
	cout << fixed << setprecision(5);
	while (t--)
	{
		int n; cin >> n ; cout << f[n] << '\n';
	}
}