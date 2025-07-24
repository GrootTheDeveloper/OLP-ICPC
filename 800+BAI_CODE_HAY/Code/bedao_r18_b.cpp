#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006],pre[1000006],fmi[1000006],fmx[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	fmi[k-1]=(int)1e18;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
		if (i>=k) 
			{
				fmx[i]=max(fmx[i-1],pre[i]-pre[i-k]);
				fmi[i]=min(fmi[i-1],pre[i]-pre[i-k]);
			}
	}
	int ans=INT_MIN;
	for (int i=2*k;i<=n;i++)
	{
		int temp=pre[i]-pre[i-k],
			mi=fmi[i-k],
			mx=fmx[i-k];
		ans=max({ans,abs(temp-mi),abs(temp-mx)});
	}
	cout << ans;

}