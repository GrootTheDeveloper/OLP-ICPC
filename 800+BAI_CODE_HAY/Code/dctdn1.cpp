#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1111],f[1111];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f[i]=1;
		for (int j=1;j<i;j++) if (a[i]>a[j]) f[i]=max(f[i],f[j]+1);
	}
	int res=0;
	for (int i=1;i<=n;i++) res=max(res,f[i]);
	cout << res;
}