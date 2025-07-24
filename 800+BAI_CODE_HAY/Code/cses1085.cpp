#include <bits/stdc++.h>
using namespace std;
#define int long long 
int res=(int)1e18;
int n,k,a[2000005],f[2000005];

bool check(int val)
{
	int pos=0,temp,sum=0;
	for (int i=1;i<=k;i++)
	{
		temp=pos;
		pos=upper_bound(f+pos,f+n+1,f[pos]+val)-f-1;
		sum=max(sum,f[pos]-f[temp]);
		if (pos==n) return res=min(res,sum),1;
	}
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i],f[i]=f[i-1]+a[i];
	if (k==1) return cout << f[n],0;
	int l=1,r=f[n];
	while (l<r) 
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (check(l-1)) l--;
	while (!check(l)) l++;
	cout << res;
}