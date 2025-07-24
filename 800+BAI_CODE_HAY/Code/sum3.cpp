#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	int n; cin >> n;
	double sum=0;
	for (int i=1;i<=n;i++)
		sum+=(double)1/(i*(i+1));
	cout << setprecision(5) << fixed << sum;
}