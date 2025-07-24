#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[100005],a[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];

	for (int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+abs(a[i]-a[i-1]);
		for (int j=i-1;j>=max(1LL,i-k);j--) f[i]=min(f[i],f[j]+abs(a[i]-a[j])); 

	}
	cout << f[n];
}