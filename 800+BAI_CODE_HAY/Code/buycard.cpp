#include <bits/stdc++.h>
using namespace std;
#define int long long 

void query()
{
	int c,p,n1,n2,t1,t2;
	cin >> c >> p >> n1 >> n2 >> t1 >> t2;
	int res=c/p;
	int l=1,r=res;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (mid*p+mid/n1*t1+mid/n2*t2 <=c) l=mid+1;
		else r=mid-1;
	}
	if (l*p+l/n1*t1+l/n2*t2 <=c) cout << l << '\n';
	else cout << l-1 << '\n';

}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) query();
}