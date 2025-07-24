#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int mi=0,res=INT_MIN,sum=0;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin >> x;
		sum+=x;
		res=max(res,sum-mi);
		mi=min(mi,sum);
	}
	cout << res;
}