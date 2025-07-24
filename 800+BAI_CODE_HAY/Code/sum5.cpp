#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
long double f[1000006];
void o_o()
{
	long double sum=0.0000;
	for (int i=1;i<=1e6;i++)
	{
		sum+=(long double)1/i;
		f[i]=sum;
	}
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	o_o();
	cout << fixed << setprecision(5);
	while (t--)
	{
		cin >> n; cout << f[n] << '\n';
	}
}