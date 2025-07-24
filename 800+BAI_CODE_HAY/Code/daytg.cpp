#include <bits/stdc++.h>
using namespace std;
#define int long long 

int l[10000007],a[10000007];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int res=0;
	for (int i=2;i<n;i++)
	{
		if (a[i]>a[i-1] && a[i]>a[i+1])
		{
			int dem=1;
			for (int j=i-1;j>=1;j--) if (a[j]<a[j+1]) dem++;else break;
			for (int j=i+1;j<=n;j++) if (a[j]<a[j-1]) dem++;else break;
			res=max(res,dem);
		}
	}
	cout << res;
}

