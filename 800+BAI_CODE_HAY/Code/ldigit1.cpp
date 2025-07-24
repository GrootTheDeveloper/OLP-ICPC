#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int k=1;
	for (int i=1;i<=n;i++)
	{
		k*=i;
		while (k%10==0) k/=10;	
		k=k%10000;
	}
	cout << k%10;
}