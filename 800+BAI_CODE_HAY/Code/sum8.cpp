#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	cout << fixed << setprecision(5);
	while (t--)
	{
		int n; cin >> n ;
		double sum=sqrt(n);
		for (int i=n-1;i>=1;i--)
			sum=sqrt(i+sum);
		cout << sum << '\n';

	}
}