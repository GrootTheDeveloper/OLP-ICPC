#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
	
	int n; cin >> n;
	int res=1,lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++) 
	if (n%i==0){
		res=n/i;
		break;
	}
	cout << res;

}