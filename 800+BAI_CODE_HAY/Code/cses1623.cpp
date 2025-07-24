#include <bits/stdc++.h>
using namespace std;
#define int long long 

int sum,a[22],res=(int)1e18,n;

void Try(int i, int s)
{
	if (i>n) return res=min(res,abs(sum-2*s)),void();
	Try(i+1,s+a[i]);
	Try(i+1,s);
	
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],sum+=a[i];
	Try(1,0);
	cout << res;
}