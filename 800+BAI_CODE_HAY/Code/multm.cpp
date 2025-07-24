#include <bits/stdc++.h>
using namespace std;
#define int long long 
unordered_map <int,int> f;
int a[100005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,p; cin >> n >> p;
	for (int i=1;i<=n;i++) cin >> a[i], f[a[i]]++;
	sort(a+1,a+n+1);
	int res=n;
	for (int i=1;i<=n;i++)
	{
		if (f[a[i]*p] && f[a[i]]) 
		{
			res-=min(f[a[i]],f[a[i]*p]);
			if (f[a[i]]<=f[a[i]*p]) f[a[i]]=0; 
			else f[a[i]*p]=0;
		}
	}
	cout << res;

}


