#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,kq,a[1000007],f[1000007],sum;

main()
{
	cin >> n >> d;
	dem[0]=1;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum=(sum+a[i]+1000000000 * d)%d;
		kq+=dem[sum];
		dem[sum]++;
	}
	cout << kq;
}